#ifndef _MALLOC_H_
# define _MALLOC_H_

void *malloc(size_t size);

void init_bins();

unsigned int get_bin_index(size_t size);

#endif
