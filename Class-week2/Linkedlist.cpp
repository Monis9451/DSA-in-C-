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

class LinkedList
{
private:
    Node *head = nullptr;

public:
    //--------------------Insertion at start
    void insertAtBegining(int data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
            cout << "Data inserted in start" << endl;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;
            cout << "Data inserted in start" << endl;
        }
    }

    //-------------------Insertion at end
    void insertAtEnd(int data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
            cout << "Data inserted at the end" << endl;
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
            cout << "Data inserted at the end" << endl;
        }
    }

    //-------------------Update at index
    void Update(int index, int data)
    {
        int currIndex = 0;
        Node *temp = head;
        Node *previous = nullptr;
        bool error = false;
        if (index < 0)
        {
            cout << "Invalid index entered" << endl;
        }
        else if (index == 0)
        {
            head->data = data;
            cout << "Data inserted at " << index << " index." << endl;
        }
        else
        {
            for (int i = 0; i < index; i++)
            {
                if (temp == nullptr)
                {
                    error = true;
                }
                previous = temp;
                temp = temp->next;
            }
            if (error)
            {
                cout << "error" << endl;
                cout << "Invalid index" << endl;
            }
            else
            {
                temp->data = data;
                cout << "Data updated" << endl;
            }
        }
    }

    void Display()
    {
        Node *temp = head;
        cout << "List: ";
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl
             << endl;
    }

    bool search(int data)
    {
        Node *temp = head;
        bool flag = true;
        while (temp != nullptr)
        {
            if (temp->data == data)
            {
                cout << "Required data found" << endl;
                flag = false;
                return true;
            }
            temp = temp->next;
        }
        if (flag)
        {
            cout << "Data not found" << endl;
            return false;
        }
    }

    void insertAfter(int index, int data)
    {
        int currIndex = 0;
        Node *temp = head;
        Node *previous = nullptr;
        bool error = false;
        if (index < 0)
        {
            cout << "Invalid index entered" << endl;
        }
        else
        {
            for (int i = 0; i < index; i++)
            {
                if (currIndex == index)
                {
                    break;
                }
                previous = temp;
                temp = temp->next;
                currIndex++;
            }
            Node *newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Data entered after required node" << endl;
        }
    }

    void Delete(int data)
    {
        Node* toDel = nullptr;
        Node* temp = head;
        Node* previous = nullptr;
        while(temp != nullptr)
        {
            if(temp->data == data)
            {
                toDel = temp;
                break;
            }
            previous = temp;
            temp = temp->next;
        }
        previous->next = temp->next;
        delete toDel;
        cout << "Data deleted" << endl;
    }

    void sortAsceding()
    {
        if(!head || !head->next)
        {
            return;
        }
        Node* temp = head;
        bool flag = true;
        while(flag)
        {
            flag = false;
            temp = head;
            while(temp->next)
            {
                if(temp->data > temp->next->data)
                {
                    swap(temp->data, temp->next->data);
                    flag = true;
                }
                temp = temp->next;
            }
        }
        cout << "Data sorted out in acsending order" << endl;
    }
    void sortDecending()
    {
        if(!head || !head->next)
        {
            return;
        }
        Node* temp = head;
        bool flag = true;
        while(flag)
        {
            flag = false;
            temp = head;
            while(temp->next)
            {
                if(temp->data < temp->next->data)
                {
                    swap(temp->data, temp->next->data);
                    flag = true;
                }
                temp = temp->next;
            }
        }
        cout << "Data sorted out in decending order" << endl;
    }
};

int main()
{

    LinkedList list;
    list.insertAtBegining(5);
    list.insertAtBegining(4);
    list.insertAtBegining(3);
    list.Display();
    list.insertAtEnd(6);
    list.insertAtEnd(7);
    list.insertAtEnd(8);
    list.Display();
    list.Update(3, 11);
    list.Display();
    cout << list.search(11) << endl << endl;
    list.insertAfter(3, 12);
    list.Display();
    list.Delete(12);
    list.Display();
    list.sortAsceding();
    list.Display();
    list.sortDecending();
    list.Display();

    return 0;
}