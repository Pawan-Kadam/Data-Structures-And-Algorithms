// Queue using Stack can be implemented using two approaches
// By making enQueue costly or by making deQueue costly
// Here in this program enQueue costly approach is discussed

/*
Time Complexity -
enQueue - O(n)
deQueue - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// enQueue costly queue
class Queue
{
public:
    stack<int> s1, s2;

    bool isEmpty();
    void enQueue(int x);
    int deQueue();
    void displayQueue();
};

// Function to check if queue is empty
bool Queue::isEmpty()
{
    if (s1.empty() && s2.empty())
    {
        return true;
    }
    return false;
}

// First push all element from s1 to s2 then push x to s1, again push elements from s2 to s1
void Queue::enQueue(int x)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    s1.push(x);

    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

// As it it enQueue costly just pop element from s1
int Queue::deQueue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }

    int x = s1.top();
    s1.pop();
    return x;
}

// Function to display queue
void Queue::displayQueue()
{
    cout << "Stack : ";
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};

    Queue q;

    for (int i = 0; i < 5; i++)
    {
        q.enQueue(A[i]);
    }

    cout << "Element deQueued : " << q.deQueue() << endl;
    q.displayQueue();

    return 0;
}
