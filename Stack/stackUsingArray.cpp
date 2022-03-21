#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *S;

    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        S = new int[size];
    }

    bool isEmpty();
    bool isFull();
    void push(int data);
    int pop();
    int peek(int pos);
    void display();
};

// Function to check if stack is empty
bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

// Function to check if stack is full
bool Stack::isFull()
{
    if (top == size - 1)
    {
        return true;
    }
    return false;
}

// Function to print stack
void Stack::display()
{
    cout << "Stack : ";
    for (int i = 0; i < size; ++i)
    {
        cout << S[i] << " ";
    }
    cout << endl;
    cout << "Top-->" << S[top] << endl;
}

// Function to push an element from stack
void Stack::push(int data)
{
    if (isFull())
    {
        cout << "Stack Overflow for " << data << endl;
    }
    else
    {
        top++;
        S[top] = data;
    }
}

// Function to pop an element from stack
int Stack::pop()
{
    int x;

    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        x = S[top];
        top--;
    }
    return x;
}

// Function to find an element at a given position
int Stack::peek(int pos)
{
    int x;

    if (pos < 0)
    {
        cout << "Enter valid position" << endl;
        return -1;
    }
    else
    {
        x = S[top - pos + 1];
    }
    return x;
}

int main()
{
    Stack st(5);
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);
    st.push(25);
    st.push(25);
    st.push(25);

    int a = st.peek(3);
    cout << "Peek " << a << endl;

    st.display();

    return 0;
}
