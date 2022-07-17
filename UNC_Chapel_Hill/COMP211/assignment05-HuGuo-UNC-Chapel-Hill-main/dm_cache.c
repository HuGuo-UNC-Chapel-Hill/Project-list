// PID: 730507803
// I pledge the COMP 211 honor code.

#include "dm_cache.h"

DMCache *createDMCache(MainMem *mem,
                     uint32_t set_index_bitcount,
                     uint32_t word_index_bitcount) {
    if (mem == NULL) {
        return NULL;
    }

    if (mem->address_width <= set_index_bitcount + word_index_bitcount + 2) {
        return NULL;
    }

    DMCache *cache = (DMCache *) malloc(sizeof(DMCache));
    cache->word_index_bitcount = word_index_bitcount;
    cache->set_index_bitcount = set_index_bitcount;
    cache->mem= mem;

    uint32_t num_lines = (1<<set_index_bitcount);
    cache->Cachelines = (DMCacheLine *) calloc(num_lines, sizeof(DMCacheLine));

    for (uint32_t i=0; i<num_lines; i++) {
           cache->Cachelines[i].valid = 0;
           cache->Cachelines[i].block = (uint32_t *) calloc((1<<word_index_bitcount), sizeof(uint32_t));     
    }

    return cache;
}

uint32_t bit_select(uint32_t num, uint32_t startbit, uint32_t endbit){
    return (num >> endbit & ~(~0 << (startbit + 1 - endbit)));
}


void freeDMCache(DMCache *cache) {
	if (cache != NULL) {
		if (cache->mem != NULL) {
			free(cache->mem);
			cache->mem = NULL;
		}  
		if (cache->Cachelines != NULL) {
			free(cache->Cachelines);
			cache->Cachelines = NULL;
		}
		free(cache);
	}
}

DMCacheResult readByte(DMCache *cache, uint32_t address, uint8_t *value) {
   
    if (cache == NULL) {
        return DM_INVALID_CACHE;
    }

    if (address >= (1<<cache->mem->address_width)) {
        return DM_CACHE_ADDRESS_OUT_OF_RANGE;
    }

    if (value == NULL) {
        return DM_INVALID_CACHE;
    }

    uint32_t line_index_start = 1+cache->word_index_bitcount+cache->set_index_bitcount;
    uint32_t line_index_end = 2+cache->word_index_bitcount;
    uint32_t line_index = bit_select(address, line_index_start, line_index_end);
    
    
    DMCacheLine *line = &cache->Cachelines[line_index]; 

    uint32_t addr_tag = address >> (cache->set_index_bitcount + cache->word_index_bitcount + 2);

    //miss meizhong cong memory read the byte
    if((!line->valid) || (line->tag != addr_tag)) {
        //Line does not have the block we want, go get it.
        uint32_t block_start_address = address & (0xffffffff << (cache->word_index_bitcount+2)); //???
        uint32_t block_size = (1 << cache->word_index_bitcount); //1<< 1 = 2   
        for (uint32_t i= 0 ; i<block_size; i++) { //block_size = 2
            readWord(cache->mem, block_start_address + (i*sizeof(uint32_t)), &(line->block[i]));  
        }
        line->valid = 1;
        line->tag = addr_tag;
    }

    //hit situation
    uint32_t word_index = bit_select(address, 2+cache->word_index_bitcount-1, 2); //2,2  --> 0  or 1 
    uint32_t word = line->block[word_index];  //1 word 1 block
    uint32_t byte_offset = address % sizeof(uint32_t);
    //32 bits word == block in cachaline
    //move to left for serival steps then mask it 
    *value = (word>> (8*byte_offset)) & (0x0000000ff); 
    return DM_CACHE_SUCCESS;
}



