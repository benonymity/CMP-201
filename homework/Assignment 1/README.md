# CMP-201-01
### Assignment 1 - 1/31/24
___
1. See `1.1.cpp`
2. See `1.2.cpp`
3. See `1.3.cpp`
4. `e`, `f`, and `i` are the only options that are valid C++ expressions.
5. The `delete` keyword can be used to free the memory set aside on the heap for `p`. But after the memory has been deallocated, the pointer itself still holds a memory address, which we can use to hold another desired variable.
6. The `new` operator sets aside memory on the heap that is properly sized to the given type and returns the address for a pointer.
7. Just referring to `data` hasn’t done anything to dereference it, so we will be adding 4 to it’s first address, which will give it it’s 5th int. If we wanted to read that 5th int, we would need to get `*(data + 4)`.