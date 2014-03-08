#ifndef _MALLOC_H_
# define _MALLOC_H_

// Globals
#define g_bins_count 11

void *malloc(size_t size);

void init_bins();

unsigned int get_bin_size(size_t size);

#endif
