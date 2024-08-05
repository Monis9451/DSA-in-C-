#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data: " << value << endl;
    }
};

// insert in start
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// insert at end
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// insert at any position
void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    // inserting in start
    if (position == 0)
    {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int pos = 0;
    // traversing
    while (pos < position - 1)
    {
        temp = temp->next;
        pos++;
    }
    // inserting at the end
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    Node *New = new Node(d);
    New->next = temp->next;
    temp->next = New;
}

void deleteAtPosition(Node *&head, int position)
{
    if (position == 0)
    {
        // deleting 1st node at 0th index
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        // deleting 1st node at 0th index
        Node* curr = head;
        Node* pre = NULL;
        int pos = 0;

        while(curr != NULL && pos < position){
            pre = curr;
            curr = curr->next;
            pos++;
        }
        if (curr == NULL)
        {
            cout << "Position out of bounds." << endl;
            return;
        }
        pre->next = curr->next;
        delete curr;
    }
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *node = new Node(10);
    Node *head = node;
    Node *tail = node;

    display(head);
    insertAtTail(tail, 12);
    display(head);
    insertAtTail(tail, 15);
    display(head);
    insertAtTail(tail, 18);
    display(head);
    insertAtTail(tail, 20);
    display(head);
    insertAtPosition(head, tail, 5, 8);
    display(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
    deleteAtPosition(head, 2);
    display(head);
    return 0;
}