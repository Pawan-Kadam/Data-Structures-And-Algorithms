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

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    LinkedList(int val)
    {
        head = new Node(val);
        tail = head;
    }

    void insertAtHead(int data);
    void insertAtTail(int data);
    void insertLL(int pos, int data);
    int getLength();
    void deleteNode(int pos);
    void displayLL();
};

// Funtion to insert a node at the start of the LL
void LinkedList::insertAtHead(int data)
{
    Node *insert = new Node(data);

    if (head == NULL)
    {
        head = insert;
        tail = insert;
    }
    else
    {
        insert->next = head;
        head = insert;
    }
}

// Funtion to insert a node at the end of the LL
void LinkedList::insertAtTail(int data)
{
    Node *insert = new Node(data);

    if (tail == NULL)
    {
        tail = insert;
        head = insert;
    }
    else
    {
        tail->next = insert;
        tail = insert;
    }
}

// Funtion to insert a node at any given position in LL
void LinkedList::insertLL(int pos, int data)
{
    if (pos < 1)
    {
        cout << "Please Enter valid position" << endl;
        return;
    }
    else if (pos == 1)
    {
        insertAtHead(data);
        return;
    }
    else
    {
        Node *temp = head;

        int cnt = 1;
        // Considering LL index from 1 not 0
        // Will trace till pos-1 as temp is already at pos = 1
        while (cnt < pos - 1)
        {
            temp = temp->next;
            cnt++;
        }

        // If temp is the tail node
        if (temp->next == NULL)
        {
            insertAtTail(data);
            return;
        }

        Node *insert = new Node(data);
        insert->next = temp->next;
        temp->next = insert;
    }
}

// Funtion to get length of the LL
int LinkedList::getLength()
{
    Node *temp = head;
    int len = 1;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// Funtion to delete a node at the given position in the LL
void LinkedList::deleteNode(int pos)
{
    if (pos < 1 || pos > getLength())
    {
        cout << "Please Enter valid position" << endl;
        return;
    }
    else if (pos == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;

        int cnt = 1;

        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        // If curr is tail node
        if (curr->next == NULL)
        {
            prev->next = NULL;
            tail = prev;
            return;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

// Funtion to display the LL
void LinkedList::displayLL()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    else
    {
        cout << "Linked List : ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        cout << "Head-->" << head->data << " | ";
        cout << "Tail-->" << tail->data;
        cout << endl;
    }
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};

    LinkedList LL;

    LL.displayLL();
    LL.insertAtHead(45);
    LL.insertAtTail(65);

    for (int i = 0; i < 5; ++i)
    {
        LL.insertLL(i + 1, A[i]);
    }

    LL.displayLL();
    LL.deleteNode(7);
    LL.displayLL();

    return 0;
}
