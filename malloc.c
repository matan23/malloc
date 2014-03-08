#include <math.h>
#include <stdlib.h>

#include "utils.h"
#include "malloc.h"
#include "init.h"


void  *malloc(size_t size)
{
  t_block *block;
  t_block *next;
  size_t  required_size;
  size_t  bin_index;

  // Add the size of our struct to the required size
  // to get the actual size required in memory
  required_size = size + sizeof(t_block);

  // Return NULL if the user requested more than the page size
  if (required_size > g_page_size)
  {
    return (NULL);
  }

  // If no memory was allocated yet, allocate our first page.
  // If it fails, return NULL
  if (allocated_mem == NULL)
  {
    allocated_mem = init_mem();
    if (allocated_mem == NULL)
    {
      return (NULL);
    }
  }

  // Determine which bin this block will be stored in
  bin_index = get_bin_index(required_size);

  // TODO: move to allocate.c ?
  // Look for an available block in the bin
  if (bins_array[bin_index] != NULL)
  {
    // Remove the block from the bin and return it
    block = bins_array[bin_index];
    block->is_free = 0;
    next = block->next;
    block->next = NULL;
    block->prev = NULL;

    // Update the bin
    bins_array[bin_index] = next;
    if (next != NULL)
    {
      next->prev = NULL;
    }

    // Return a pointer offset by the size of our block data
    return (block + 1);
  }

  // No available block was found

}

unsigned int get_bin_index(size_t size)
{
  unsigned int result;
  unsigned int max;

  max = pow(2, g_bins_count - 1);

  result = (unsigned int) pow(2, ceil(log(size)/log(2)));
  if (result > max)
  {
    return (max);
  }
  else
  {
    return (result);
  }
}
