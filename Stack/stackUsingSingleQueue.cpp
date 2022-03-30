// Stack using Single Queue
// Time Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    queue<int> q;

    void push(int x);
    void pop();
    int top();
};

// Funtion to push into stack
void Stack::push(int x)
{
    int s = q.size();

    q.push(x);

    // Moving already present element to rear end of queue
    for (int i = 0; i < s; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

// Funtion to pop from stack
void Stack::pop()
{
    if (q.empty())
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    else
    {
        q.pop();
    }
}

// Funtion to get top of the stack
int Stack::top()
{
    if (q.empty())
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    return q.front();
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
