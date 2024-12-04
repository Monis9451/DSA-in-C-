#include <iostream>
using namespace std;

class Node
{
    public:
    int key;
    Node *next;

    Node(int data)
    {
        this->key = data;
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
        if(!head)
        {
            head = new Node(data);
            tail = head;
            tail->next = head;
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
    }
    
    void insertAtTail(int data)
    {
        if(!head)
        {
            insertAtHead(data);
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtIndex(int index, int data)
    {
        if(index < 0)
        {
            cout << "Invalid index" << endl;
        }
        else
        {
            Node *newNode = new Node(data);
            Node *temp = head;
            int currIndex = 0;
            bool flag = true;
            while(temp)
            {
                if(currIndex == index)
                {
                    flag = false;
                    break;
                }
                temp = temp->next;
                if(temp == head)
                {
                    break;
                }
            }
            if(flag)
            {
                cout << "Invalid index" << endl;
            }
            else
            {
                newNode->next = temp->next;
                temp->next = newNode;    
            }
        }
    }

    void DeleteNode(int data)
    {
        Node *temp = head;
        Node *prev = nullptr;
        while(temp)
        {
            if(temp->key == data)
            {
                prev->next = temp->next;
                delete[] temp;
                break;
            }
            prev = temp;
            temp = temp->next;
            if(temp == head)
            {
                break;
            }
        }
    }
};

int main()
{

    return 0;
}