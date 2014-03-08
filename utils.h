#ifndef _UTILS_H_
# define _UTILS_H_

#include <unistd.h>
#include <stdlib.h>

# define PAGE_SIZE 1024

typedef struct s_block
{
  char            is_free;
  size_t          size;
  struct s_block  *next;
  struct s_block   *prev;
} t_block;

/**
 * Pointer to the beginnig of the memory allocated to our program.
 * This is updated on each sbrk call we perform.
 */
void      *allocated_mem;

/**
 * The bin sizes are as follows :
 * 8, 16, 32, 64, 128, 256, 512, 1024
 */
t_block   *bins_array[8];



#endif
