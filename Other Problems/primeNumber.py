'''
A number that is divisible only by itself and 1 
(e.g. 2, 3, 5, 7, 11).
'''

def isPrime(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


n = 15

if (isPrime(n)):
    print("Prime Number")
else:
    print("Not a Prime Number")
