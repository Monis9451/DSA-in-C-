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
        next = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
    public:
    Node *head = nullptr;
    
    void insertAtHead(int d)
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void removeFromEnd(int index)
    {
        int newIndex = 0;
        Node *temp1 = head;
        Node *temp2 = head;
        Node *toDel = nullptr;
        while(temp1->next)
        {
            if(newIndex == index || newIndex > index)
            {
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
            newIndex++;
        }
        toDel = temp2->next;
        temp2->next = toDel->next;
        delete[] toDel;
    }

};

int main()
{
    LinkedList list;
    list.insertAtHead(10);
    list.insertAtHead(9);
    list.insertAtHead(8);
    list.insertAtHead(7);
    list.insertAtHead(6);
    list.insertAtHead(5);
    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);
    list.display();
    list.removeFromEnd(3);
    list.display();

    return 0;
}