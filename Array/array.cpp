/*
Array create, insert, display and delete operations
Time Complexities -
Delete - Worst O(n)  &  Best O(1)
*/

#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;

public:
    Array(int size)
    {
        this->size = size;
        A = new int[size];
    }

    void insert();
    void display();
    void deleteElement(int pos);
};

// Function to insert elements in array
void Array::insert()
{
    int val{0};
    for (int i = 0; i < size; ++i)
    {
        cin >> val;
        A[i] = val;
    }
    cout << "Done Inserting" << endl;
}

// Function to display elements from array
void Array::display()
{
    cout << "Array : " << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Function to delete elements from array
void Array::deleteElement(int index)
{
    if (index <= size)
    {
        for (int i = index; i <= size; ++i)
        {
            // Shifting elements
            A[i] = A[i + 1]; // here we replace A[i] with the next element A[i+1]
        }
        size--; // As after deleting an element array size deacrese by 1
    }
    else
    {
        cout << "Please Enter index within range of : " << size << endl;
    }
}

int main()
{
    int size{0}, index{0};
    cout << "Enter the size of the array : " << endl;
    cin >> size;

    Array arr(size);

    cout << "Enter " << size << " elements to insert into array : " << endl;
    arr.insert();

    arr.display();

    cout << "Enter the index position of an element to delete : ";
    cin >> index;
    arr.deleteElement(index);

    arr.display();

    return 0;
}
