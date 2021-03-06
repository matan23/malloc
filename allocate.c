#include <stdlib.h>
#include "allocate.h"
#include "utils.h"


static void	init_block(t_block *block)
{
	block->is_free = 1;
	block->size = g_page_size;
	block->next = NULL;
	block->prev = NULL;
}

static void* offset_pointer(t_block * ptr, int offset) {
  char *offset_ptr = (char *) ptr;
  if (offset)
  	return offset_ptr + sizeof(t_block);
  return offset_ptr - sizeof(t_block);
}

static void		setup_new_page()
{
	t_block	*new_page;
	t_block *biggest_block;


	new_page = sbrk(g_page_size);
	if (!new_page)
		return;
	init_block(new_page);
    
    biggest_block = bins_array[g_last_bins_index];
    if (biggest_block)
    	biggest_block->next = new_page;
   	else
   		biggest_block = new_page;        
}
 

static char	get_block_index(unsigned int bin_index)
{
	int 	index;

	index = bin_index;
	while (!bins_array[index])
    	++index;
    if (index > g_bins_count)
    	return (-1);
    return (--index);
}

static t_block			*setup_new_block(t_block *new, t_block *cur_block)
{
	new = (t_block *) ((t_block *)cur_block + cur_block->size);
    new->size = cur_block->size;
    return (new);
}

static void			*break_memory_for_index_based_on_bin_index(unsigned int index, unsigned int bins_index)
{
	t_block		*cur_block;
	t_block		*new;
	t_block 	*ret;

	while (index != bins_index)
	{
		cur_block = bins_array[index];
		cur_block->size /= 2;
    
    	new = setup_new_block(new, cur_block);
	    if (bins_array[index]->next)
	    {
	      bins_array[index] = bins_array[index]->next;
	      bins_array[index]->prev = NULL;
	    }
	    else
	    {
	      bins_array[index] = NULL;
	    }
	    --index;

	    cur_block->next = new;
	    new->prev = cur_block;
	    bins_array[index] = cur_block;
	}
  	

  	if (bins_array[index]->next) {
  		bins_array[index] = bins_array[index]->next;
  		bins_array[index]->prev = NULL;
  	}
  	else
  	{
  		bins_array[index] = NULL;
  	}
	ret = bins_array[index];
  	ret->next = NULL;
  	ret->is_free = 1;

  return offset_pointer(ret, 1);
}

void		*resize_page_for_size(unsigned int bin_index)
{
	int 	index;
	void	*ptr;

	index = get_block_index(bin_index);
	if (index < 0)
    	setup_new_page();
   ptr = break_memory_for_index_based_on_bin_index(index, bin_index);
  return (ptr);
}
