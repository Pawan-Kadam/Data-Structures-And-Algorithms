// Queue using Stack can be implemented using two approaches
// By making enQueue costly or by making deQueue costly

// In this approach the best optimal solution is discussed which takes constant time to enQueue & deQueue

/*
Time Complexity - (Amortized Time Complexity)
enQueue - O(1)
deQueue - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Amortized O(1) queue
class Queue
{
public:
    stack<int> s1, s2;

    bool isEmpty();
    void enQueue(int x);
    int deQueue();
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

// First push element to s1
void Queue::enQueue(int x)
{
    s1.push(x);
}

// As it it Amortized costly just pop element from s2
int Queue::deQueue()
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int x = s2.top();
    s2.pop();
    return x;
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
    cout << "Element deQueued : " << q.deQueue() << endl;

    return 0;
}
