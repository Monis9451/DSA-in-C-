#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *previous;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->previous = nullptr;
        this->next = nullptr;
    }
};

class DLinkedlist
{
public:
    Node *head = nullptr;
    Node *tail = nullptr;

    void insertAtHead(int data)
    {
        if (head == nullptr && tail == nullptr)
        {
            head = new Node(data);
            tail = head;
            cout << "Data " << data << " inserted in the start" << endl;
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
            cout << "Data " << data << " inserted in the start" << endl;
        }
    }

    void deleteData(int data)
    {
        if (head == nullptr && tail == nullptr)
        {
            cout << "Linked list is empty there is nothing to delete" << endl;
        }
        else
        {
            bool flag = true;
            Node *temp = head;
            while (temp->next)
            {
                if (temp->data == data)
                {
                    flag = false;
                    break;
                }
                temp = temp->next;
            }
            if (flag)
            {
                cout << "Data to delete not found" << endl;
            }
            else
            {
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                delete[] temp;
                cout << "Required data " << data << " deleted" << endl;
            }
        }
    }

    void forwardDisplay()
    {
        if (head == nullptr && tail == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void reverseDisplay()
    {
        if (head == nullptr && tail == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = tail;
            while (temp)
            {
                cout << temp->data << "->";
                temp = temp->previous;
            }
            cout << endl;
        }
    }

    void insertAfterIndex(int index, int data)
    {
        if (index < 0)
        {
            cout << "Invalid index" << endl;
        }
        else if (index == 0)
        {
            insertAtHead(data);
        }
        else
        {
            Node* newNode = new Node(data);
            Node *temp = head;
            int currIndex = 0;
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
                cout << "Invalid index" << endl;
            }
            else
            {
                newNode->next = temp->next;
                newNode->previous = temp;
                temp->next->previous = newNode;
                temp->next = newNode;
                cout << "Data inserted at the required index" << endl;
            }
        }
    }

    void totalNodes()
    {
        if (head == nullptr && tail == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;
            int index = 0;
            while(temp->next)
            {
                index++;
                temp = temp->next;
            }
            cout << "Linked list have " << index << " node(s)" << endl;
        }
    }

    void traverseList()
    {
        Node *temp = head;
        while(temp->next)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        while(temp)
        {
            cout << temp->data << "->";
            temp = temp->previous;
        }
        cout << endl;
    }

    void merging2SortedList(DLinkedlist L1, DLinkedlist L2)
    {

    }
};

int main()
{
    DLinkedlist List;
    cout << "Inserting data at head" << endl;
    List.insertAtHead(5);
    List.insertAtHead(4);
    List.insertAtHead(3);
    List.insertAtHead(2);
    cout << "Displaying data in forward manner" << endl;
    List.forwardDisplay();
    cout << "Displaying data in reverse manner" << endl;
    List.reverseDisplay();
    cout << "Delete some data" << endl;
    List.deleteData(4);
    cout << "Displaying data in forward manner" << endl;
    List.forwardDisplay();
    cout << "Number od nodes in data" << endl;
    List.totalNodes();
    cout << "Traversing the list" << endl;
    List.traverseList();
    DLinkedlist List2;
    DLinkedlist List3;
    cout << "Merging 2 lists" << endl;
    List.merging2SortedList(List2, List2);

    return 0;
}