# CMP-201-01
### Friday, March 1 - Class 19

- Factorial complexity appears in ordering a collection
- We don't care about [infinte monkeys](https://en.wikipedia.org/wiki/Infinite_monkey_theorem) here
- Hash functions again
- Probing: Just go to the next open spot!

**Linear Probing Example:**
| A | Fool | And | His | Money | Are | Soon | Parted |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 9 | 6 | 10 | 7 | 11 | 11 | 12 |

**Hash Table:**
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
| -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
| Parted | A | | | | | And | Money | | Fool | His | Are | Soon |

**Deletion:** Remove soon, replace with something else (lazy deletion). In reality, we'd want to be smart and rehash parted to move it to 12

Quadratic probing is also a thing, we just spread it out (1, 2, 4, 8, 16, etc.)

**More hashing:** $\rightarrow$ Hash it again! $(h(k) + s(k))\mod m$ where $h(k)$ is the original hash function, and $s(k)$ is another hash function

- Chaining: When you have a collision, you build a list
- [Python dict](https://github.com/python/cpython/blob/3.12/Lib/dataclasses.py)