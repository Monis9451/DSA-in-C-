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
        next = NULL;
    }
};

class linkedList
{
public:
    Node *head = NULL;

    //----------------Insert at start---------------
    void insertAtStart(int d)
    {
        if (head == NULL)
        {
            head = new Node(d);
        }
        else
        {
            Node *temp = new Node(d);
            temp->next = head;
            head = temp;
        }
    }

    //----------------Insert at end---------------
    void insertAtEnd(int d)
    {
        if (head == NULL)
        {
            head = new Node(d);
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            Node *newNode = new Node(d);
            temp->next = newNode;
        }
    }

    //----------------insert at index--------
    void insertAtIndex(int index, int d)
    {
        if (index < 0)
        {
            cout << "Invalid index" << endl;
        }
        else if (index == 0)
        {
            insertAtStart(d);
        }
        else
        {
            bool flag;
            Node *previous = NULL;
            Node *current = head;
            for (int i = 0; i < index; i++)
            {
                if (current == NULL)
                {
                    flag = true;
                    break;
                }
                previous = current;
                current = current->next;
            }
            if (flag)
            {
                cout << "Index in not reachable!" << endl;
            }
            else
            {
                Node *newNode = new Node(d);
                previous->next = newNode;
                newNode->next = current;
            }
        }
    }

    //----------------Deleting the node-------------
    void deleteAtIndex(int index)
    {
        if (index < 0)
        {
            cout << "Invalid index" << endl;
        }
        else if (index == 0)
        {
            Node *toDel = head;
            head = head->next;
            delete toDel;
        }
        else
        {
            Node *prev = NULL;
            Node *curr = head;
            for (int i = 0; i < index; i++)
            {
                if (curr == NULL)
                {
                    cout << "Index in unreachable" << endl;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
        }
    }

    //----------------Searching index---------------
    bool searchIndex(Node *temp, int data)
    {
        if (temp == NULL)
        {
            return false;
        }
        if (temp->data == data)
        {
            return true;
        }
        return searchIndex(temp->next, data);
    }

    //----------------Printing forward--------------
    void forwardPrint()
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
            cout << endl;
        }
    }

    //----------------Printing reverse---------------
    void reversePrint(Node *temp)
    {
        if(temp == NULL){
            return;
        }
        reversePrint(temp->next);
        cout<<temp->data<<"->";
    }
};

int main()
{
    linkedList node;
    node.insertAtStart(8);
    node.insertAtStart(7);
    node.insertAtEnd(10);
    node.insertAtIndex(2, 9);
    node.insertAtEnd(11);
    node.forwardPrint();
    node.deleteAtIndex(4);
    cout<< "Search '9' : "<<node.searchIndex(node.head, 9)<<endl;
    node.forwardPrint();
    node.reversePrint(node.head);
    return 0;
}