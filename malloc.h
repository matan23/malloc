#ifndef _MALLOC_H_
# define _MALLOC_H_

// Globals
#define g_bins_count 11

typedef struct  s_block
{
  struct s_block *next;
  unsigned int size;
} t_block;

t_block         *bins_array[g_bins_count];

void *malloc(size_t size);

void free(void *ptr);

void init_bins();

unsigned int get_bin_size(size_t size);

#endif
