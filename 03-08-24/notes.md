# CMP-201-01
### Friday, March 8 - Class 22

- When there are problems, abstract away one layer (pointers!!)
- Polymorphism: dynamic binding
- `virtual` and `override` keywords
- Multiple inheritance!

```mermaid
flowchart TB
A[Thing]
B[Item]
C[Desk]
D[Book]
E[Pen]
F[Firearm]
A-->B & C
B-->D & E
C-->E & F
```