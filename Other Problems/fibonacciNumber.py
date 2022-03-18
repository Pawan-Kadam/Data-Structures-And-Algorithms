def fibonacciNumber(n, a, b):
    c = 0
    for i in range(2, n+1):
        c = a + b
        a = b
        b = c
    return c


n = 10
a = 0
b = 1

print("Fibonacci Sequence -> ", end=" ")
for i in range(n):
    print(fibonacciNumber(i, a, b), end=" ")

print("\nNth Fibonacci -> ", fibonacciNumber(n-1, a, b))
