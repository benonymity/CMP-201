# CMP-201-01
### Monday, Feburary 19 - Class 14

**C++ vs. Python:**
| C++ | Python |
| --- | --- |
| `int x = 4;` | `x = 4` |
| Stack: 0x400 = 4, Heap is empty | Stack: 0x400 -> 0x900, Heap: 0x900 = 4 |
| `x = "Hillsdale";` | `x = "Hillsdale"`|
| Compiler error, not enough space for a string. dynamic typing doesn't work with stack and heap | Takes it in stride, because everything is a pointer! Stack: 0x400 -> 0x950 & 0x404 -> 0x904, Heap: 0x900 = 4 & 0x950 = "Hillsdale"|
| | `y = "College"` |
| | Stack: 0x400 -> 0x900 & 0x404 -> 0x904, Heap: 0x900 = 4 & 0x904 = "College" & |
| | `z = x + 1` |
| | Stack: 0x400 -> 0x900 & 0x404 -> 0x904 & 0x408 -> 0x912, Heap: 0x900 = "Hillsdale" & 0x904 = "College" & 0x908 = 5 |
| | `a = [1, 2, 3]` |
| | Adds 0x412 -> 0x912 to the stack and 0x940 = [1,2,3] to the heap |
| | `b = a` |
| | Adds 0x416 -> 0x912 to the stack |

Python tries to be efficient by using pointers for multiple variables equaling each other, but will do a deep copy if you try to change it to keep the user from thinking about low level memory management.

**Wednesday Exam**
- Understand coding constructs
- Write a line here or there of C++
- Understand efficieny and memory management
- Read and understand code and diagnose problems
- Lists pop and push back
- Understand templates
- Mostly short answer questions
- Understand differences between arrays and lists