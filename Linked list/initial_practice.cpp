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
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}


void insertAtTail(Node *&tail, int d){
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
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
    Node* head = node;
    Node* tail = node;

    display(tail);
    insertAtTail(head,12);
    display(tail);
    insertAtTail(head,15);
    display(tail);
    return 0;
}