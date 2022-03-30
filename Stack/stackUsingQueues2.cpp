// Stack using Queues can be implemented using two approaches
// By making push costly or by making pop costly
// Here in this program pop costly approach is discussed

/*
Time Complexity -
pop - O(n)
psuh - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Pop costly stack
class Stack
{
public:
    queue<int> q1, q2;

    void push(int x);
    int top();
    void pop();
    bool isEmpty();
};

// Funtion to push into stack
void Stack::push(int x)
{
    // Push to q1
    q1.push(x);
}

// Funtion to pop from stack
void Stack::pop()
{
    int x;
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return;
    }
    else
    {
        // Leave one element to q1 and push others to q2
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Pop the only left element from q1
        q1.pop();

        // Swapping q1 q2
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
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
        // Leave one element to q1 and push others to q2
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Pop the only left element from q1
        x = q1.front();
        q1.pop();
        q2.push(x);

        // Swapping q1 q2
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
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
