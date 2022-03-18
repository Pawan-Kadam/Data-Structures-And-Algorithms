'''
The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..
Fn = Fn-1 + Fn-2
'''

def fibonacciNumber(n):
    if n <= 1:
        return n
    return fibonacciNumber(n-1) + fibonacciNumber(n-2)


n = 10

print("Fibonacci Sequence -> ", end=" ")
for i in range(n):
    print(fibonacciNumber(i), end=" ")

print("\nRecursive -> ", fibonacciNumber(n-1))
