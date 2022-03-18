#include <iostream>
using namespace std;

int fibonacciNumber(int n, int a, int b)
{
    int c = 0;
    for (int i = 2; i <= n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n = 10;
    int a = 0, b = 1;

    cout << "Fibonacci Sequence -> ";
    for (int i = 0; i < n; ++i)
    {
        cout << fibonacciNumber(i, a, b) << " ";
    }
    cout << endl;

    cout << "Recursive -> " << fibonacciNumber(n - 1, a, b) << endl;

    return 0;
}
