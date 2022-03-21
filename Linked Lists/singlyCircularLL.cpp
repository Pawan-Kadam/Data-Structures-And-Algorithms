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

class CircularLinkedList
{
private:
    Node *tail;

public:
    CircularLinkedList()
    {
        tail = NULL;
    }

    // As it is circular LL single node points itself making it circular
    CircularLinkedList(int val)
    {
        tail = new Node(val);
        tail->next = tail;
    }

    void insertLL(int element, int data);
    int getLength();
    void deleteNode(int val);
    void displayLL();
};

// Function to insert node after node with element
void CircularLinkedList::insertLL(int element, int data)
{
    Node *insert = new Node(data);

    // As it is circular LL single node points itself making it circular
    if (tail == NULL)
    {
        tail = insert;
        tail->next = tail;
    }
    else
    {
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        insert->next = curr->next;
        curr->next = insert;
    }
}

// Funtion to display LL
void CircularLinkedList::displayLL()
{
    Node *temp = tail;

    if (temp == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    else
    {
        cout << "Circular Linked List : ";

        // do-while to maintain if LL contains single node i.e. tail
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail);
        cout << endl;
    }
}

// Funtion to get length of the LL
int CircularLinkedList::getLength()
{
    Node *temp = tail;
    int len = 0;

    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        // do-while to maintain if LL contains single node i.e. tail
        do
        {
            len++;
            temp = temp->next;
        } while (temp != tail);
    }
    return len;
}

// Funtion to delete node with element
void CircularLinkedList::deleteNode(int element)
{
    if (tail == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // If LL contains single node
        if (curr == prev)
        {
            tail = NULL;
        }

        // If curr is tail node
        else if (tail == curr)
        {
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    CircularLinkedList LL(2);

    LL.displayLL();

    LL.insertLL(2, 5);
    LL.insertLL(5, 6);

    LL.displayLL();

    cout << LL.getLength() << endl;

    LL.deleteNode(5);
    LL.displayLL();
    cout << LL.getLength();

    return 0;
}
