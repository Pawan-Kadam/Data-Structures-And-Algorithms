#include <iostream>
using namespace std;

// Linear Search Algorithm
int linearSearch(int A[], int n, int key)
{
    for (int i = 0; i < n; ++i)
    {
        if (A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// Function to display Array
void displayArray(int A[], int n)
{
    for (int i{0}; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n{5}, k{0}, ans{0};
    int A[n] = {1, 2, 3, 4, 5};

    cout << "The Array is : ";
    displayArray(A, n);

    cout << "Enter the element to search : ";
    cin >> k;

    ans = linearSearch(A, n, k);

    cout << "The element is present at index is : " << ans;

    return 0;
}
