#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }

    // As it is circular LL single node points itself making it circular
    CircularLinkedList(int data)
    {
        head = new Node(data);
        head->next = head;
        head->prev = head;
    }

    void insertLL(int element, int data);
    int getLength();
    void deleteNode(int element);
    void displayLL();
};

// Function to insert node after node with element
void CircularLinkedList::insertLL(int element, int data)
{
    Node *insert = new Node(data);

    // As it is circular LL single node points itself making it circular
    if (head == NULL)
    {
        head = insert;
        head->next = head;
        head->prev = head;
    }
    else
    {
        Node *curr = head;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        curr->next->prev = insert;
        insert->next = curr->next;
        curr->next = insert;
        insert->prev = curr;
    }
}

// Funtion to get length of the LL
int CircularLinkedList::getLength()
{
    Node *temp = head;
    int len = 0;

    if (head == NULL)
    {
        return len;
    }
    else
    {
        cout << "Linked List : ";
        do
        {
            len++;
            temp = temp->next;
        } while (temp != head);
    }
    return len;
}

// Funtion to delete node with element
void CircularLinkedList::deleteNode(int element)
{
    Node *last = head;
    Node *curr = last->next;

    while (curr->data != element)
    {
        last = curr;
        curr = curr->next;
    }

    // If LL contains single node
    if (curr == last)
    {
        head = NULL;
    }

    // If curr is head node
    else if (head == curr)
    {
        last->next = curr->next;
        curr->next->prev = curr->prev;
        head = last;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
        return;
    }

    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

// Funtion to display LL
void CircularLinkedList::displayLL()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }
    else
    {
        cout << "Linked List : ";
        // do-while to maintain if LL contains single node i.e. head
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    cout << endl;
    cout << "Head-->" << head->data << endl;
}

int main()
{
    CircularLinkedList LL(2);

    LL.displayLL();

    LL.insertLL(2, 5);
    LL.insertLL(5, 6);

    LL.displayLL();

    // cout << LL.getLength() << endl;

    LL.deleteNode(6);
    LL.displayLL();
    // cout << LL.getLength();

    return 0;
}
