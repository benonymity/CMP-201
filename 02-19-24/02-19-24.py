x: int = 4000
print(id(x))
print(x)

# x = "Hillsdale"
# print(x)
# Python doesn't really care about types because it keeps everything in pointers on the heap

y: str = "College"
print(id(y))
print(y)

z = x + 1
print(id(z))
print(z)

a = [1, 2, 3]
b = a
print(id(a))
print(id(b))
print(b)

w = x
print(id(x))
print(x) 