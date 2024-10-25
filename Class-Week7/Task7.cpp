#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

bool searchValue(Node *head, int value)
{
    if(head->data == value)
        return true;
    if(!head)
        return false;
    return searchValue(head->next, value);
}

void insertAtEnd(Node*& head, int data)
{
    if (head == nullptr)
    {
        head = new Node(data);
        cout << "Data inserted at the end." << endl;
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
        cout << "Data inserted at the end." << endl;
    }
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
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
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    printList(head);
    cout << searchValue(head, 4) << endl;

    return 0;
}