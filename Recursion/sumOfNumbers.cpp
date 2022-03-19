// Program to print sum of first n numbers

#include <iostream>
using namespace std;

int sum(int n)
{
    if (n <= 0)
    {
        return n;
    }
    return n + sum(n - 1);
}

int main()
{
    int n = 10;
    cout << sum(n) << endl;
    return 0;
}
