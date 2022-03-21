#include <iostream>
using namespace std;

/*
Binary Search Algorithm
This algorithms works for sorted array only
If array is not sorted the first sort the array and the perform binary search
Best Case - O(1)  // If the middle element is key
Worst case - O(log n)
Space - O(1)
*/


// Recursive binary search
int binarySearchRecursive(int A[], int start, int end, int key)
{
    if (start <= end)
    {
        // int mid = (start + end) / 2;
        // This approach fails for larger values as it may contain bugs

        int mid = start + (end - start) / 2;
        // The above approach is most suitable for larger values

        if (key == A[mid])
        {
            return mid;
        }
        else if (key < A[mid])
        {
            return binarySearchRecursive(A, start, mid, key);
        }

        return binarySearchRecursive(A, mid + 1, end, key);
    }
    return -1;
}

// Iterative binary search
int binarySearchIterative(int A[], int s, int e, int key)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (key == A[mid])
        {
            return mid;
        }
        else if (key < A[mid])
        {
            e = mid;
        }
        else
        {
            s = mid + 1;
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

    ans = binarySearchRecursive(A, 0, n, k);
    // ans = binarySearchIterative(A, 0, n, k);

    cout << "The element is present at index is : " << ans;

    return 0;
}
