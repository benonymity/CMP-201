# CMP-201-01
### Monday, January 22 - Class 3

- Compilers and symbol tables
- Arrays & memory locations
- A variable is the simplest data structure, next an array, etc.
- Memory locations (in this case spaced by 4)
- How appending works
- Integer arithmatic is the thing computers are best at
- Dynamic memory allocation (because state needs to grow, not just change)
- Stack (static, automatic storage) vs. Heap (dynamic, manually accessible storage)
- To build an appendable list, we need to use the heap
- We can't use names in the heap, only addresses
- So we need to distinguish between a value and an address
- `*` means dereference
- Adding `&` creates a reference