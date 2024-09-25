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

    void insertAtTail(int data)
    {
        if (head == nullptr && tail == nullptr)
        {
            head = new Node(data);
            tail = head;
            cout << "Data " << data << " inserted in the tail" << endl;
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
            cout << "Data " << data << " inserted in the tail" << endl;
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

    void merging2SortedList(DLinkedlist &L1, DLinkedlist &L2)
    {
        Node *L1head = L1.head;
        Node *L1tail = L1.tail;
        Node *L2head = L2.head;
        Node *L2tail = L2.tail;
        DLinkedlist mergedList;
        Node *mHead = mergedList.head;
        Node *mTail = mergedList.tail;
        Node *temp1 = L1head;
        Node *temp2 = L2head;
        while(temp1->next != nullptr && temp2->next != nullptr)
        {
            if(temp1->next == nullptr && temp2->next)
            {
                while(temp2->next)
                {
                    if(mHead == nullptr)
                    {
                        mHead = new Node (temp2->data);
                        mTail = mHead;
                    }
                    else
                    {
                        Node *newNode = new Node(temp2->data);
                        newNode->previous = mTail;
                        mTail->next = newNode;
                        mTail = newNode;
                    }
                    temp2 = temp2->next;
                }
            }
            if(temp2->next == nullptr && temp1->next)
            {
                while(temp1->next)
                {
                    if(mHead == nullptr)
                    {
                        mHead = new Node (temp1->data);
                        mTail = mHead;
                    }
                    else
                    {
                        Node *newNode = new Node(temp1->data);
                        newNode->previous = mTail;
                        mTail->next = newNode;
                        mTail = newNode;
                    }
                    temp1 = temp1->next;
                }
            }
            if(temp1->data < temp2->data)
            {
                if(mHead == nullptr)
                {
                    mHead = new Node (temp1->data);
                    mTail = mHead;
                }
                else
                {
                    Node *newNode = new Node(temp1->data);
                    newNode->previous = mTail;
                    mTail->next = newNode;
                    mTail = newNode;
                }
                temp1 = temp1->next;
            }
            if(temp1->data > temp2->data)
            {
                if(mHead == nullptr)
                {
                    mHead = new Node (temp2->data);
                    mTail = mHead;
                }
                else
                {
                    Node *newNode = new Node(temp2->data);
                    newNode->previous = mTail;
                    mTail->next = newNode;
                    mTail = newNode;
                }
                temp2 = temp2->next;
            }
            if(temp1->data == temp2->data)
            {
                if(mHead == nullptr)
                {
                    mHead = new Node (temp1->data);
                    mTail = mHead;

                    Node *newNode = new Node(temp2->data);
                    newNode->previous = mTail;
                    mTail->next = newNode;
                    mTail = newNode;
                }
                else
                {
                    Node *newNode = new Node(temp1->data);
                    newNode->previous = mTail;
                    mTail->next = newNode;
                    mTail = newNode;

                    newNode = new Node(temp2->data);
                    newNode->previous = mTail;
                    mTail->next = newNode;
                    mTail = newNode;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        cout << "Linked list merged" << endl;
        mergedList.forwardDisplay();
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
    cout << "Inserting data at tail" << endl;
    List.insertAtTail(6);
    List.insertAtTail(7);
    List.insertAtTail(8);
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
    List2.insertAtHead(7);
    List2.insertAtHead(5);
    List2.insertAtHead(4);
    List2.insertAtHead(1);
    List2.forwardDisplay();
    DLinkedlist List3;
    List3.insertAtHead(6);
    List3.insertAtHead(4);
    List3.insertAtHead(3);
    List3.insertAtHead(2);
    List3.forwardDisplay();
    cout << "Merging 2 lists" << endl;
    List.merging2SortedList(List2, List2);

    return 0;
}