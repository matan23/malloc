malloc
======

Simple implementation of malloc to better undertands memory management
    

#check if pointer is between the allowed boundaries of the heap.  
- bottom: (address returned by first call to sbrk) -> too low to make sense
- top: ?
- (address in boundary but does not make point to any node): magic number
  
#Use your library
- create .so (shared library)
- modify path of $LD_PRELOAD to point to my library

#Some programs use their own implementation of malloc
- write on stderr or stdout to check if your malloc is really called or not
- 
#algoritms
-  Boundary tags
-  Binning
