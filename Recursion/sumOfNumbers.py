# Program to print sum of first n numbers

def sumOfNumbers(n):
    if n <= 0:
        return n
    else:
        return n + sumOfNumbers(n - 1)


n = 100
print(sumOfNumbers(n))
