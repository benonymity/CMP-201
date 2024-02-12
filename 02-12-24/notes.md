# CMP-201-01
### Monday, Feburary 12 - Class 12

- Exam next week
    - written, no computers
    - e.g. write dangling pointer example
    - fix this block of code/say what's wrong
- Homework 3 on class design
- Shallow copy (stack only) vs. deep copy (stack & heap, can make changes without changing original)
- Take the AI course!
- `typename` now replaces `class`
- Linked list: store first address on stack, but all others with the values themselves.
- Want delete, insert, and append operators
- Linear data structures
- To append, we iterate to end, then add a new node
- To insert, we iterate to the number before where we want to insert, replace the address to point to what you're inserting, then point to the one after in what you insert
- Usually the last item points to null, but circular lists point to the first item again
- To delete: iterate to one before the node we want to delete, point it to the one after the node we want to delete, then free the memory of the node we want to delete
- Doubly linked list: pointer to the next and the last item