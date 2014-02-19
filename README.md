malloc
======

Simple implementation of malloc to better undertands memory management
    

check if pointer is between the allowed boundaries of the heap.  
- bottom: (address returned by first call to sbrk) -> too low to make sense
- top: ?
- (addres in boundary but does not make point to any node): magic number 
