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
            cout << "Data inserted in start." << endl;
        }
        else
        {
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;
            cout << "Data inserted in start." << endl;
        }
    }

    //-------------------Insertion at end
    void insertAtEnd(int data)
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

    //-------------------Update at index
    void Update(int index, int data)
    {
        int currIndex = 0;
        Node *temp = head;
        Node *previous = nullptr;
        bool error = false;
        if (index < 0)
        {
            cout << "Invalid index entered." << endl;
        }
        else if (index == 0)
        {
            head->key = data;
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
                cout << "error." << endl;
                cout << "Invalid index." << endl;
            }
            else
            {
                temp->key = data;
                cout << "Data updated." << endl;
            }
        }
    }

    //-------------------Displaying linked list
    void Display()
    {
        Node *temp = head;
        cout << "List: ";
        while (temp != nullptr)
        {
            cout << temp->key << " -> ";
            temp = temp->next;
            if(temp == head)
            {
                break;
            }
        }
        cout << endl
             << endl;
    }

    //-------------------Searching in linked list
    bool search(int data)
    {
        Node *temp = head;
        bool flag = true;
        while (temp != nullptr)
        {
            if (temp->key == data)
            {
                cout << "Required data found." << endl;
                flag = false;
                return true;
            }
            temp = temp->next;
        }
        if (flag)
        {
            cout << "Data not found." << endl;
            return false;
        }
    }

    //-------------------Inset after the given index of linked list
    void insertAfter(int index, int data)
    {
        int currIndex = 0;
        Node *temp = head;
        Node *previous = nullptr;
        bool error = false;
        if (index < 0)
        {
            cout << "Invalid index entered." << endl;
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
            cout << "Data entered after required node." << endl;
        }
    }

    //-------------------Delete the given data of linked list
    void Delete(int data)
    {
        if(head->key == data)
        {
            Node *toDel = head;
            head = head->next;
            delete[] toDel;
        }
        else
        {
            Node *toDel = nullptr;
            Node *temp = head;
            Node *previous = nullptr;
            while (temp != nullptr)
            {
                if (temp->key == data)
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
    }

    //-------------------Sorting in ascending order
    void sortAsceding()
    {
        if (!head || !head->next)
        {
            return;
        }
        Node *temp = head;
        bool flag = true;
        while (flag)
        {
            flag = false;
            temp = head;
            while (temp->next)
            {
                if (temp->key > temp->next->key)
                {
                    swap(temp->key, temp->next->key);
                    flag = true;
                }
                temp = temp->next;
            }
        }
        cout << "Data sorted out in acsending order." << endl;
    }

    //-------------------Sorting in decending order
    void sortDecending()
    {
        if (!head || !head->next)
        {
            return;
        }
        Node *temp = head;
        bool flag = true;
        while (flag)
        {
            flag = false;
            temp = head;
            while (temp->next)
            {
                if (temp->key < temp->next->key)
                {
                    swap(temp->key, temp->next->key);
                    flag = true;
                }
                temp = temp->next;
            }
        }
        cout << "Data sorted out in decending order." << endl;
    }

    //-------------------Sorting in ascending order
    void acsendingSortedInsertion(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else if (data < head->key)
        {
            insertAtBegining(data);
        }
        else
        {
            Node *temp = head;
            Node *previous = nullptr;
            while (temp && temp->key < data)
            {
                previous = temp;
                temp = temp->next;
            }
            if (previous != nullptr)
            {
                previous->next = newNode;
                newNode->next = temp;
            }
            cout << "Data entered in Ascending order." << endl;
        }
    }

    //-------------------Sorting in decending order
    void decendingSortedInsertion(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else if (data > head->key)
        {
            insertAtBegining(data);
        }
        else
        {
            Node *temp = head;
            Node *previous = nullptr;
            while (temp && temp->key > data)
            {
                previous = temp;
                temp = temp->next;
            }
            if (previous != nullptr)
            {
                previous->next = newNode;
                newNode->next = temp;
            }
            cout << "Data entered in Ascending order." << endl;
        }
    }

    //-------------------Find the middle of the linked list
    void Middle()
    {
        int index = 0;
        Node *temp = head;
        while (temp)
        {
            index++;
            temp = temp->next;
        }
        index = (index / 2);
        temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        cout << "The middle data of linked list is: " << temp->key << "." << endl;
    }

    //--------------------Find the number of times the data appears in the list
    void numberOfData(int data)
    {
        Node *temp = head;
        int times = 0;
        while(temp->next)
        {
            if(temp->key == data)
            {
                times++;
            }
            temp = temp->next;
        }
        cout << "The " << data << " appears " << times << " times in the list." << endl;
    }

    //--------------------Find the linked list is circular or not
    bool isCircular()
    {
        Node *temp = head;
        temp = temp->next;
        bool flag = true;
        while(temp->next)
        {
            if(temp == head)
            {
                flag = false;
                return true;
                break;
            }
            temp = temp->next;
        }
        if(flag)
        {
            return false;
        }
    }

    //--------------------Making the linked list circular
    void makingCirculer()
    {
        if(head == nullptr)
        {
            cout << "Linkedlist is empty" << endl;
        }
        else
        {
            Node *temp = head;
            while(temp->next)
            {
                temp = temp->next;
            }
            temp->next = head;
            cout << "Linked list converted to circular linked list" << endl;
        }
    }

    void makingUncircular()
    {
        if(head == nullptr)
        {
            cout << "Linkedlist is empty" << endl;
        }
        else
        {
            Node *temp = head;
            Node *prev = nullptr;
            while(temp->next)
            {
                prev = temp;
                temp = temp->next;
                if(temp == head)
                {
                    break;
                }
            }
            prev->next = nullptr;
            cout << "Converted to uncircular linked list" << endl;
        }
    }

    void exchnagingFirstnLastNodes()
    {
        Node *temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }
        int tempData = temp->key;
        temp->key = head->key;
        head->key = tempData;
        cout << "The nodes are exchanged now" << endl;
    }

    void merge(LinkedList *List1, LinkedList *List2, LinkedList *List3)
    {
    Node *head1 = List1->head;
    Node *head2 = List2->head;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while(temp1 != nullptr && temp2 != nullptr)
    {
        if(temp1->key < temp2->key)
        {
        List3->insertAtEnd(temp1->key);
        temp1 = temp1->next;
        }
        else if(temp2->key < temp1->key)
        {
        List3->insertAtEnd(temp2->key);
        temp2 = temp2->next;
        }
        else if(temp1->key == temp2->key)
        {
        List3->insertAtEnd(temp1->key);
        temp1 = temp1->next;
        List3->insertAtEnd(temp2->key);
        temp2 = temp2->next;
        }
        else if(temp1 == nullptr)
        {
        while(temp2 != nullptr);
        List3->insertAtEnd(temp2->key);
        temp2 = temp2->next;
        }
        else if(temp2 == nullptr)
        {
        while(temp1 != nullptr);
        List3->insertAtEnd(temp1->key);
        temp1 = temp1->next;
        }
    }
    List3->Display();
    }
};

int main()
{

    LinkedList list;
    list.insertAtBegining(5);
    list.insertAtBegining(4);
    list.insertAtBegining(3);
    list.insertAtBegining(2);
    list.Display();
    list.insertAtEnd(6);
    list.insertAtEnd(7);
    list.insertAtEnd(8);
    list.Display();
    list.Update(3, 11);
    list.Display();
    cout << list.search(11) << endl
         << endl;
    list.insertAfter(3, 12);
    list.Display();
    list.Delete(12);
    list.Display();
    list.sortDecending();
    list.Display();
    list.decendingSortedInsertion(13);
    list.Display();
    list.sortAsceding();
    list.Display();
    list.acsendingSortedInsertion(11);
    list.Display();
    list.Middle();
    list.numberOfData(11);
    cout << "Is the given linked list is circular? : " << list.isCircular() << endl;
    list.makingCirculer();
    cout << "Is the given linked list is circular? : " << list.isCircular() << endl;
    list.Display();
    list.makingUncircular();
    list.exchnagingFirstnLastNodes();
    list.Display();
    LinkedList List1;
    List1.insertAtEnd(3);
    List1.insertAtEnd(5);
    List1.insertAtEnd(6);
    LinkedList List2;
    List2.insertAtEnd(2);
    List2.insertAtEnd(4);
    List2.insertAtEnd(7);
    LinkedList List3;
    list.merge(&List1, &List2, &List3);

    return 0;
}