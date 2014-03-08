#include "utils.h"
#include "init.h"

void *init_mem()
{
  void *temp;
  unsigned int i;

  // Request a page in memory
  temp = sbrk(g_page_size);
  // If sbrk failed, the malloc call should return NULL
  if (temp == NULL)
  {
    return (NULL);
  }

  // Place the new page/block in the approriate bin
  i = g_bins_count - 1;
  bins_array[i] = (t_block *) temp;
  bins_array[i]->next = NULL;
  bins_array[i]->prev = NULL;
  bins_array[i]->size = g_page_size;
  bins_array[i]->is_free = 1;

  return (temp);
}
