#include <iostream>
using namespace std;

class Node
{
    public:
    int key;
    Node *next;
    Node(int val) : key(val), next(nullptr) {}
};

Node* insertAtTail(Node *head, int value)
{
    if(head->next == nullptr)
    {
        Node *newNode = new Node(value);
        head->next = newNode;
        cout << "Data inserted at the end recursively." << endl;
    }
    else
    {
        insertAtTail(head->next, value);
    }
    return head;
}

void insertAtEnd(Node*& head, int data)
{
    if (head == nullptr)
    {
        head = new Node(data);
        cout << "Data inserted at the end simply." << endl;
    }
    else
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Data inserted at the end simply." << endl;
    }
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->key << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    Node *head = nullptr;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    printList(head);
    head = insertAtTail(head, 4);
    head = insertAtTail(head, 5);
    printList(head);

    return 0;
}