#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        this->top = NULL;
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
    if (top == NULL)
    {
        return true;
    }
    return false;
}

// Function to check if stack is full
bool Stack::isFull()
{
    // Creating a new node just to check if memory is present in heap or not
    Node *temp = new Node(1);

    if (temp == NULL)
    {
        return true;
    }
    delete temp;
    return false;
}

// Function to print stack
void Stack::display()
{
    Node *temp = top;

    cout << "Stack : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Top-->" << top->data << endl;
}

// Function to push an element from stack
void Stack::push(int data)
{
    if (isFull())
    {
        cout << "Stack Overflow for " << data << endl;
        return;
    }
    else
    {
        Node *insert = new Node(data);
        insert->next = top;
        top = insert;
    }
}

// Function to pop an element from stack
int Stack::pop()
{
    int x = -1;

    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return x;
    }
    else
    {
        Node *temp = top;
        x = top->data;
        top = top->next;
        temp->next = NULL;
        delete temp;
    }
    return x;
}

// Function to find an element at a given position
int Stack::peek(int pos)
{
    if (pos < 0)
    {
        cout << "Enter valid position" << endl;
        return -1;
    }
    else
    {
        int cnt = 1;
        Node *t = top;

        while (cnt < pos)
        {
            t = t->next;
            cnt++;
        }

        if (t != NULL)
        {
            return t->data;
        }
    }
    return -1;
}

int main()
{

    Stack st;
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);
    st.push(25);
    st.push(35);
    st.display();
    st.pop();
    st.display();

    return 0;
}
