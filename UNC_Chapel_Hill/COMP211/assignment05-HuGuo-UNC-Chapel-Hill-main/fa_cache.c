// PID: 730507803
// I pledge the COMP 211 honor code.

#include "fa_cache.h"
#include <stdio.h>

uint32_t counter;

// uint32_t bit_select1(uint32_t num, uint32_t startbit, uint32_t endbit)
// {
//     return (num >> endbit & ~(~0 << (startbit + 1 - endbit)));
// }

uint32_t bit_select(uint32_t num, uint32_t startbit, uint32_t endbit) {
    unsigned int topmask = 0xffffffff;
    return (num >> endbit) & (~(topmask << (startbit-endbit+1)));
}

FACache *createFACache(MainMem *mem,
                       uint32_t word_index_bitcount,
                       uint32_t num_cache_lines)
{
    if (mem == NULL)
    {
        return NULL;
    }

    if (mem->address_width <= word_index_bitcount + 2)
    {
        return NULL;
    }

    FACache *cache = (FACache *)malloc(sizeof(FACache));
    cache->num_of_cachelines = num_cache_lines;
    cache->word_index_bitcount = word_index_bitcount;
    cache->mem = mem;
    cache->lines = (FACacheLine *)calloc(num_cache_lines, sizeof(FACacheLine));

    for (uint32_t i = 0; i < num_cache_lines; i++)
    {
        cache->lines[i].valid = 0;
        cache->lines[i].block = (uint32_t *)calloc((1 << word_index_bitcount), sizeof(uint32_t));
        cache->lines[i].last_used = 0;
    }

    return cache;
}

void freeFACache(FACache *cache)
{
    if (cache != NULL)
    {
        if (cache->mem != NULL)
        {
            free(cache->mem);
            cache->mem = NULL;
        }
        if (cache->lines != NULL)
        {
            free(cache->lines);
            cache->lines = NULL;
        }
        free(cache);
    }
}

void checkCache(FACache *cache)
{
    for (uint32_t i = 0; i < cache->num_of_cachelines; i++)
    {
        printf("[%d], %d  %d %d\n", i, cache->lines[i].last_used,
        cache->lines[i].block[0],cache->lines[i].block[1]);
    }
    printf("\n");
}

// function to find the index of least used line
uint32_t LRU_index(FACache *cache)
{

    uint32_t index = 0;
    uint32_t min = cache->lines[index].last_used;

    for (uint32_t i = 1; i < cache->num_of_cachelines; i++)
    {
        if (cache->lines[i].last_used < min)
        {
            min = cache->lines[i].last_used;
            index = i;
        }
    }
    return index;
}

FACacheResult readByte(FACache *cache, uint32_t address, uint8_t *value)
{

    if (cache == NULL)
    {
        return FA_INVALID_CACHE;
    }

    if (address >= (1 << cache->mem->address_width))
    {
        return FA_CACHE_ADDRESS_OUT_OF_RANGE;
    }

    if (value == NULL)
    {
        return FA_INVALID_VALUE_PTR;
    }

    uint32_t addr_tag = address >> (cache->word_index_bitcount + 2);
    // uint32_t addr_tag = address >> 2;
    FACacheLine *line = NULL;

    //checkCache(cache);
    int setup = 0;

    counter++;

    // firstly matching tag to all cache lines
    for (uint32_t i = 0; i < cache->num_of_cachelines && setup == 0; i++)
    {
        //printf("matching existed tag\n");
        if (cache->lines[i].tag == addr_tag && cache->lines[i].valid == 1)
        {
            line = &cache->lines[i];
            line->last_used = counter;
            setup = 1;
        }
    }

    for (uint32_t i = 0; i < cache->num_of_cachelines && setup == 0; i++)
    {
        //printf("matching empty tag\n");
        if (cache->lines[i].valid == 0 && setup == 0)
        {
            line = &cache->lines[i];
            uint32_t block_start_address = address & (0xffffffff << (cache->word_index_bitcount + 2));
            uint32_t block_size = (1 << cache->word_index_bitcount);
            for (uint32_t i = 0; i < block_size; i++)
            {
                readWord(cache->mem, block_start_address + (i * sizeof(uint32_t)), &(line->block[i]));
            }
            line->valid = 1;
            line->tag = addr_tag;
            line->last_used = counter;
            setup = 1;
        }
    }

    if (!line && setup == 0)
    {
        //printf("lru replace\n");
        uint32_t least_index = LRU_index(cache);
        line = &cache->lines[least_index];
        uint32_t block_start_address = address & (0xffffffff << (cache->word_index_bitcount + 2));
        uint32_t block_size = (1 << cache->word_index_bitcount);
        for (uint32_t i = 0; i < block_size; i++)
        {
            readWord(cache->mem, block_start_address + (i * sizeof(uint32_t)), &(line->block[i]));
        }
        line->valid = 1;
        line->tag = addr_tag;
        line->last_used = counter;
        setup = 1;
    }

    // get the block from the address
    uint32_t word_index = bit_select(address, 2 + cache->word_index_bitcount - 1, 2);
    uint32_t word = line->block[word_index];
    uint32_t byte_offset = address % sizeof(uint32_t);

    *value = (word >> (8 * byte_offset)) & (0x0000000ff);
    return FA_CACHE_SUCCESS;
}

FACacheResult writeByte(FACache *cache, uint32_t address, uint8_t value)
{

    if (cache == NULL)
    {
        return FA_INVALID_CACHE;
    }

    if (address >= (1 << cache->mem->address_width))
    {
        return FA_CACHE_ADDRESS_OUT_OF_RANGE;
    }

    counter++;

    uint32_t addr_tag = address >> 3;

    FACacheLine *line;
    //checkCache(cache);

    uint32_t hit = 0;

    for (uint32_t i = 0; i < cache->num_of_cachelines && hit == 0; i++)
    {
        //printf(" writeByte()\n");
        if (cache->lines[i].tag == addr_tag && cache->lines[i].valid == 1 && hit == 0)
        {
            line = &cache->lines[i];
            line->last_used = counter;
            hit = 1;
        }

    }

    uint32_t word_index = bit_select(address, 2, 2);
    uint32_t word = line->block[word_index];
    uint32_t byte_offset = address % sizeof(uint32_t);
	uint32_t transValue = value;
	
    if (byte_offset == 3)
    {
        word &= 0x00FFFFFF;
        transValue <<= 24;
    }
    if (byte_offset == 2)
    {
        word &= 0xFF00FFFF;
        transValue <<= 16;
    }
    if (byte_offset == 1)
    {
        word &= 0xFFFF00FF;
        transValue <<= 8;
    }
    if (byte_offset == 0)
    {
        word &= 0xFFFFFF00;

    }
    word |= transValue;
    //checkCache(cache);
    line->block[word_index] = word;
    //checkCache(cache);
    // writeWord(cache->mem, address, word);

    uint32_t start_address = address & (0xffffffff << (cache->word_index_bitcount + 2));
    writeWord(cache->mem, start_address, word);
    
    return FA_CACHE_SUCCESS;
}