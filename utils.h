#ifndef _UTILS_H_
# define _UTILS_H_

#include <unistd.h>
#include <stdlib.h>

# define PAGE_SIZE sysconf(_SC_PAGESIZE)

typedef struct s_block
{
  char            is_free;
  size_t          size;
  struct s_block  *next;
  struct s_block   *prev;
} t_block;

void  *allocated_mem;




#endif
