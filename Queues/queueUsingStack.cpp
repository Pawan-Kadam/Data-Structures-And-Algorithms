// Queue using Stack can be implemented using two approaches
// By making enQueue costly or by making deQueue costly
// Here in this program deQueue costly approach is discussed

/*
Time Complexity -
enQueue - O(1)
deQueue - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// deQueue costly queue
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

// As it it deQueue costly just pushing element to s1
void Queue::enQueue(int x)
{
    s1.push(x);
}

// First push all elements from s1 to s2 the take top of s2 as deQueued element
int Queue::deQueue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

    int x = s2.top();
    s2.pop();
    return x;
}

// Function to display queue
void Queue::displayQueue()
{
    cout << "Stack : ";
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
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
