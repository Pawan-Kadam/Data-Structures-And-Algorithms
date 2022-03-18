#include <iostream>
using namespace std;

int fibonacciNumber(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacciNumber(n - 1) + fibonacciNumber(n - 2);
}

int main()
{
    int n = 10;

    cout << "Fibonacci Sequence -> ";
    for (int i = 0; i < n; ++i)
    {
        cout << fibonacciNumber(i) << " ";
    }
    cout << endl;

    cout << "Recursive -> " << fibonacciNumber(n - 1) << endl;

    return 0;
}
