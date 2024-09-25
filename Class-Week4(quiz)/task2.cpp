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
        this->next = nullptr;
    }
};

class Linkedlist
{
public:
    Node *head = nullptr;

    void insertAtHead(int data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
            cout << "Data inserted" << endl;
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = head;
            head = newNode;
            cout << "Data inserted" << endl;
        }
    }

    void reverse()
    {
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    int findNthFromLast(int n)
    {
        reverse();
        int currIndex = 1;
        Node *temp = head;
        while(head)
        {
            if(currIndex == n)
            {
                return temp->data;
            }
            temp = temp->next;
            currIndex++;
        }
        return;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
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
    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);
    cout << list.findNthFromLast(3);

    return 0;
}