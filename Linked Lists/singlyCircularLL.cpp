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
    Node *head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }

    // As it is circular LL single node points itself making it circular
    CircularLinkedList(int val)
    {
        head = new Node(val);
        head->next = head;
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
    if (head == NULL)
    {
        head = insert;
        head->next = head;
    }
    else
    {
        Node *curr = head;

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
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    else
    {
        cout << "Circular Linked List : ";

        // do-while to maintain if LL contains single node i.e. head
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
        cout << "Head-->" << head->data << endl;
    }
}

// Funtion to get length of the LL
int CircularLinkedList::getLength()
{
    Node *temp = head;
    int len = 0;

    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        // do-while to maintain if LL contains single node i.e. head
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
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    else
    {
        Node *prev = head;
        Node *curr = prev->next;

        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }

        // If LL contains single node
        if (curr == prev)
        {
            head = NULL;
        }

        // If curr is head node
        if (head == curr)
        {
            prev->next = curr->next;
            head = prev;
            curr->next = NULL;
            delete curr;
            return;
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

    LL.deleteNode(2);
    LL.deleteNode(6);
    LL.deleteNode(5);
    LL.displayLL();
    cout << LL.getLength();

    return 0;
}
