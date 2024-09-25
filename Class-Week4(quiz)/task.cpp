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
        this->prev = nullptr;
        this->next = nullptr;
    }
};


class Linkedlist
{
    public:
    Node *head = nullptr;
    Node *tail = nullptr;

    void insertAtHead(int data)
    {
        if(head == nullptr)
        {
            head = new Node(data);
            tail = head;
            cout << "Data inserted" << endl;
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            cout << "Data inserted" << endl;
        }
    }

    void rotateByN(int n)
    {
        Node *temp = head;
        Node *Head = head;
        bool flag = true;
        while(temp != nullptr)
        {
            if(temp->data == n)
            {
                flag = false;
                break;
            }
            temp = temp->next;
        }
        if(flag)
        {
            cout << "Value not found" << endl;
        }
        else
        {
            head = temp->next;
            tail->next = Head;
            tail = temp;
            tail->next = nullptr;
        }
    }

    void display()
    {
        Node *temp = head;
        while(temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Linkedlist list;
    list.insertAtHead(8);
    list.insertAtHead(7);
    list.insertAtHead(6);
    list.insertAtHead(5);
    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);
    list.display();
    cout << "data displayed" << endl;
    list.rotateByN(4);
    list.display();

    return 0;
}