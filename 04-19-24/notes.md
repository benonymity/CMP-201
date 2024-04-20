# CMP-201-01
### Friday, April 19 - Class 32

    - Heuristic algorithm with approximate solutions
- [Knapsack Problem](https://en.wikipedia.org/wiki/Knapsack_problem)
    - Given $n$ items of weight $w_1, \dots, w_n$ and values $v_1, \dots, v_n$ and a knapsack of capacity $W$. Find the most valuable subset of item that fill the knapsack
    - Exhaustive: Exponential growth
    - Greedy: Local optimality criterion (value per weight, highest value, lowest weight)
- [Travelling Salesman Problem](https://en.wikipedia.org/wiki/Travelling_salesman_problem)
    - Complete graph (every pair of nodes connected by a unique edge)
    - ExhausiveL Factorial :(
    1. Represent the solution:
        - Label nodes in the order visited. (e.g. if 9 nodes, then 213 954 876, 532 689 714)
        - Value: sum of weights
    