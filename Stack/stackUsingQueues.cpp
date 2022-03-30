// Stack using Queues can be implemented using two approaches
// By making push costly or by making pop costly
// Here in this program push costly approach is discussed

/*
Time Complexity -
pop - O(1)
psuh - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Push costly stack
class Stack
{
public:
    queue<int> q1, q2;

    void push(int x);
    void pop();
    int top();
    bool isEmpty();
};

// Funtion to push into stack
void Stack::push(int x)
{
    // Push to q2
    q2.push(x);

    // Pop from q1 and Push to q2
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    // Swapping q1 q2
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
}

// Funtion to pop from stack
void Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return;
    }
    else
    {
        q1.pop();
    }
}

// Funtion to get top from stack
int Stack::top()
{
    int x;
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    else
    {
        x = q1.front();
    }
    return x;
}

// Funtion to check if stack is empty
bool Stack::isEmpty()
{
    if (q1.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};

    Stack s;

    for (int i = 0; i < 5; i++)
    {
        s.push(A[i]);
    }

    cout << "Element at top : " << s.top() << endl;
    s.pop();
    cout << "Element at top : " << s.top() << endl;

    return 0;
}
