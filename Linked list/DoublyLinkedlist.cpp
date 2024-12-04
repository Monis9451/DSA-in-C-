#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *previous;
    Node *next;

    // constructor
    Node(int data)
    {
        this->key = data;
        this->previous = nullptr;
        this->next = nullptr;
    }
};

class Linkedlist
{
    Node *head = nullptr;

    public:
    void insertAtHead(int data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
            cout << "Node with data " << data << " inserted at the head" << endl;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = head;
            head->previous = temp;
            head = temp;
            cout << "Node with data " << data << " inserted at the head" << endl;
        }
    }

    void insertAtTail(int data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
            cout << "Node with data " << data << " inserted at the tail" << endl;
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
            newNode->previous = temp;
            cout << "Node with data " << data << " inserted at the tail" << endl;
        }
    }

    void forwardPrint()
    {
        if (head == nullptr)
        {
            cout << "The Linked list is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void printReverse()
    {
        if(head == nullptr)
        {
            cout << "The Linked list is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while(temp->next)
            {
                temp = temp->next;
            }
            while(temp)
            {
                cout << temp->key << "->";
                temp = temp->previous;
            }
            cout << endl;
        }
    }

    void deleteValue(int data)
    {
        if(head == nullptr)
        {
            cout << "The Linked list is empty, there is nothing to delete" << endl;
        }
        else
        {
            Node *temp = head;
            while(temp->key != data)
            {
                temp = temp->next;
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            delete[]temp;
            cout << "The required data "<< data <<" Deleted successfully" <<endl;
        }
    }

    void insertAfterindex(int index, int data)
    {if(head == nullptr)
        {
            insertAtHead(data);
        }
        else
        {
            int currIndex = 0;
            Node *newNode = new Node(data);
            Node *temp = head;
            bool flag = true;
            while(temp->next)
            {
                if(currIndex == index)
                {
                    flag = false;
                    break;
                }
                temp = temp->next;
                currIndex++;
            }
            if(flag)
            {
                cout << "Index to insert not found" << endl;
            }
            else
            {
                newNode->previous = temp;
                newNode->next = temp->next;
                temp->next->previous = newNode;
                temp->next = newNode;
                cout << "New Node inserted at the require index" << endl;
            }
        }

    }
};

int main()
{
    Linkedlist List;
    cout << "Inserting in start" << endl;
    List.insertAtHead(5);
    List.insertAtHead(4);
    List.insertAtHead(3);
    cout << "Printing in forward manner" << endl;
    List.forwardPrint();
    cout << "Inserting at end" << endl;
    List.insertAtTail(6);
    List.insertAtTail(7);
    List.insertAtTail(8);
    cout << "Printing in forward manner" << endl;
    List.forwardPrint();
    cout << "Printing in reverse manner" << endl;
    List.printReverse();
    cout << "Deleteing a value" << endl;
    List.deleteValue(7);
    cout << "Printing in forward manner" << endl;
    List.forwardPrint();
    cout << "Entering data in given index" << endl;
    List.insertAfterindex(3,7);
    cout << "Printing in forward manner" << endl;
    List.forwardPrint();

    return 0;
}