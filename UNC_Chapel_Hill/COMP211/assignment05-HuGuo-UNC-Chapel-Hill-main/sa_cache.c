// PID: 730507803
// I pledge the COMP 211 honor code.

#include "sa_cache.h"
#include <stdio.h>

uint32_t counter;

uint32_t bit_select(uint32_t num, uint32_t startbit, uint32_t endbit)
{
    unsigned int topmask = 0xffffffff;
    return (num >> endbit) & (~(topmask << (startbit - endbit + 1)));
}

SACache *createSACache(MainMem *mem,
                       uint32_t set_index_bitcount,
                       uint32_t word_index_bitcount,
                       uint32_t cache_lines_per_set)
{
    if (mem == NULL)
    {
        return NULL;
    }

    if (mem->address_width <= set_index_bitcount + word_index_bitcount + 2)
    {
        return NULL;
    }

    SACache *cache = (SACache *)malloc(sizeof(SACache));
    cache->set_num = 1 << set_index_bitcount;
    cache->num_cache_lines = cache->set_num * cache_lines_per_set;
    cache->word_index_bits = word_index_bitcount;
    cache->set_index_bitcount = set_index_bitcount;
    cache->cache_lines_per_set = cache_lines_per_set;
    cache->mem = mem;
    cache->lines = (SACacheLine *)calloc(cache->num_cache_lines, sizeof(SACacheLine));

    uint32_t index = 0;
    //cache->set_num = 4;
    for (uint32_t i = 0; i < cache->set_num; i++)
    {
        for (uint32_t j = 0; j < cache->cache_lines_per_set; j++)
        {
            cache->lines[index].set = i;
            // printf("index %d  set %d \n", index, i);
            index++;
        }
    }

    for (uint32_t j = 0; j < cache->num_cache_lines; j++)
    {

        cache->lines[j].valid = 0;
        cache->lines[j].dirty = 0;
        cache->lines[j].last_used = 0;
        cache->lines[j].block = (uint32_t *)calloc((1 << word_index_bitcount), sizeof(uint32_t));
    }

    // checkCache(cache);

    return cache;
}

void freeSACache(SACache *cache)
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

SACacheResult readByte(SACache *cache, uint32_t address, uint8_t *value)
{
    if (cache == NULL)
    {
        return SA_INVALID_CACHE;
    }

    if (address >= (1 << cache->mem->address_width))
    {
        return SA_CACHE_ADDRESS_OUT_OF_RANGE;
    }

    if (value == NULL)
    {
        return SA_INVALID_VALUE_PTR;
    }

    counter++;
    // checkCache(cache);
    uint32_t addr_tag = address >> (cache->set_index_bitcount + cache->word_index_bits + 2);

    SACacheLine *line;
    uint32_t set_index_start = 1 + cache->word_index_bits + cache->set_index_bitcount;
    uint32_t set_index_end = 2 + cache->word_index_bits;
    uint32_t set_index = bit_select(address, set_index_start, set_index_end);

    int setup = 0;

    for (uint32_t i = 0; i < cache->num_cache_lines && setup == 0; i++)
    {
        // printf("Matching tag\n");
        if (cache->lines[i].set == set_index && cache->lines[i].tag == addr_tag && cache->lines[i].valid == 1 && setup == 0)
        {
            line = &cache->lines[i];
            // if (line->dirty == 1)
            // {
            //     uint32_t word_index = bit_select(line->return_address, 2, 2);
            //     uint32_t start_address = line->return_address & (0xffffffff << (cache->word_index_bits + 2));
            //     writeWord(cache->mem, start_address+ (word_index * sizeof(uint32_t)), line->block[word_index]);
            //     line->dirty = 0;
            // }
            line->last_used = counter;
            setup = 1;
        }
    }

    for (uint32_t i = 0; i < cache->num_cache_lines && setup == 0; i++)
    {
        // printf("finding empty line\n");
        if (cache->lines[i].set == set_index && cache->lines[i].valid == 0 && setup == 0)
        {
            line = &cache->lines[i];
            uint32_t block_start_address = address & (0xffffffff << (cache->word_index_bits + 2));
            uint32_t block_size = (1 << cache->word_index_bits);
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

    if (setup == 0)
    {
        // printf("lru replace\n");
        uint32_t least_index = LRU_index(cache, set_index);
        line = &cache->lines[least_index];

        if (line->dirty == 1)
        {
            uint32_t word_index = bit_select(line->return_address, 2+cache->word_index_bits-1, 2);
            uint32_t start_address = line->return_address & (0xffffffff << (cache->word_index_bits + 2));
            writeWord(cache->mem, start_address + (word_index * sizeof(uint32_t)), line->block[word_index]);
            line->dirty = 0;
        }

        uint32_t block_start_address = address & (0xffffffff << (cache->word_index_bits + 2));
        uint32_t block_size = (1 << cache->word_index_bits);
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
    uint32_t word_index = bit_select(address, 2+cache->word_index_bits-1, 2);
    uint32_t word = line->block[word_index];
    uint32_t byte_offset = address % sizeof(uint32_t);

    *value = (word >> (8 * byte_offset)) & (0x0000000ff);

    return SA_CACHE_SUCCESS;
}

SACacheResult writeByte(SACache *cache, uint32_t address, uint8_t value)
{
    if (cache == NULL)
    {
        return SA_INVALID_CACHE;
    }

    if (address >= (1 << cache->mem->address_width))
    {
        return SA_CACHE_ADDRESS_OUT_OF_RANGE;
    }

    counter++;
    // checkCache(cache);
    uint32_t addr_tag = address >> (cache->set_index_bitcount + cache->word_index_bits + 2);

    SACacheLine *line;
    uint32_t set_index_start = 1 + cache->word_index_bits + cache->set_index_bitcount;
    uint32_t set_index_end = 2 + cache->word_index_bits;
    uint32_t set_index = bit_select(address, set_index_start, set_index_end);
    // checkCache(cache);

    uint32_t hit = 0;

    for (uint32_t i = 0; i < cache->num_cache_lines && hit == 0; i++)
    {

        if (cache->lines[i].set == set_index && cache->lines[i].tag == addr_tag && cache->lines[i].valid == 1 && hit == 0)
        {
            // printf(" writeByte()\n");
            line = &cache->lines[i];
            line->return_address = address;
            line->dirty = 1;
            line->last_used = counter;
            hit = 1;
        }
    }

    uint32_t word_index = bit_select(address, 2+cache->word_index_bits-1, 2);
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
    // checkCache(cache);
    line->block[word_index] = word;
    // checkCache(cache);
    //  writeWord(cache->mem, address, word);

    return SA_CACHE_SUCCESS;
}

void flushCache(SACache *cache)
{
    SACacheLine *line;
    for (uint32_t i = 0; i < cache->num_cache_lines; i++)
    {
        line = &cache->lines[i];
        if (line->dirty == 1)
        {
            uint32_t word_index = bit_select(line->return_address, 2+cache->word_index_bits-1, 2);
            uint32_t start_address = line->return_address & (0xffffffff << (cache->word_index_bits + 2));
            writeWord(cache->mem, start_address + (word_index * sizeof(uint32_t)), line->block[word_index]);
            line->dirty = 0;
            line->tag = 0;
            line->valid = 0;
            line->return_address = 0;
            counter++;
            line->last_used = counter;
        }
    }
}

void checkCache(SACache *cache)
{
    for (uint32_t j = 0; j < cache->num_cache_lines; j++)
    {
        printf("set[%d]  valid %d  tag %d  dirty %d last_used %d  block0 %x  block1 %x\n",
               cache->lines[j].set,
               cache->lines[j].valid,
               cache->lines[j].tag,
               cache->lines[j].dirty,
               cache->lines[j].last_used,
               cache->lines[j].block[0],
               cache->lines[j].block[1]);
    }
    printf("\n");
}

uint32_t LRU_index(SACache *cache, uint32_t set_index)
{
    // if(set_index == 0) {
    //     uint32_t index = 0;
    //     uint32_t min = cache->lines[index].last_used;

    //     for (uint32_t i = 1; i < cache->cache_lines_per_set; i++)
    //     {
    //         if (cache->lines[i].last_used < min)
    //         {
    //             min = cache->lines[i].last_used;
    //             index = i;
    //         }
    //     }
    //     return index;
    // } else {
    //     uint32_t index = 4;
    //     uint32_t min = cache->lines[index].last_used;

    //     for (uint32_t i = 5; i < cache->num_cache_lines; i++)
    //     {
    //         if (cache->lines[i].last_used < min)
    //         {
    //             min = cache->lines[i].last_used;
    //             index = i;
    //         }
    //     }
    //     return index;
    // }

    uint32_t index = set_index * cache->cache_lines_per_set;
    uint32_t set_max_index = index + cache->cache_lines_per_set;
    uint32_t min = cache->lines[index].last_used;

    for (uint32_t i = index + 1; i < set_max_index; i++)
    {
        // printf("i %d \n", i);
        if (cache->lines[i].last_used < min)
        {
            min = cache->lines[i].last_used;
            index = i;
        }
    }
    return index;
}
