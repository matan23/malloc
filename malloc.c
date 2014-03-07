#include <math.h>
#include <stdlib.h>
#include "malloc.h"


void  *malloc(size_t size)
{
  t_block       *new_block;
  unsigned int  bin_size;

  // TODO: deplacer dans allocate()
  // Determine which bin this block will be stored in,
  // taking into account the size of our block in addition to
  // the required size.
  bin_size = get_bin_size(size + sizeof(t_block));

  // Check if there is enough space left
  // if so, store the block in the bin
  new_block = allocate(size);
  if (!new_block)
  {
    // TODO: Try to fuse available blocks
    //       New sbrk if unable to do so
    //       return(NULL) if sbrk failed

    return (NULL);
  }
  else
  {
    return (new_block + 1);
  }

  return (NULL);
}

void  free(void *ptr)
{

}

void  init_bins()
{
  int i;

  for (i = 0; i < g_bins_count; i++)
  {
    bins_array[i] = NULL;
  }
}

unsigned int get_bin_size(size_t size)
{
  unsigned int result;
  unsigned int max;

  max = pow(2, g_bins_count - 1);

  result = (unsigned int) pow(2, ceil(log(x)/log(2)));
  if (result > max)
  {
    return (max);
  }
  else
  {
    return (result);
  }
}
