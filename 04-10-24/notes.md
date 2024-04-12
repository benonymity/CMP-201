# CMP-201-01
### Wednesday, April 10 - Class 28

- Heap: Binary tree with priority, find/delete elements with highest priority
    1. Shape property: All levels are full except (optionally) the last
    2. Heap property: Key in a node is greater than or equal to the key in its sucessors
- Heaps & Arrays: A heap can be represented not just with nodes, but also as an array with levels, or an array of arrays, such that the children of parent $i$ are in positinos $2i$ and $2i+1$ (start the array with an empty slot to avoid $2\times0$)
- Heapsort: 
    1. Construct a heap from an array
    2. Apply root deletion to the remaining heap
- Huffman Tree: 
    - Binary tree: 
        - left node = 0
        - right node = 1
        - leaf nodes are symbols
    