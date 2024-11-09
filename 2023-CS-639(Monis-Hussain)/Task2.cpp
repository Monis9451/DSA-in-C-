#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int orderID;
        Node *next;
        Node(int id) : orderID(id), next(nullptr) {}
    };

    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    //Linkedlist Functions (History)

    void addOrder(int orderID)
    {
        Node *newNode = new Node(orderID);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Order " << orderID << " added to the order history." << endl;
    }

    bool retrieveOrderByID(int orderID)
    {
        Node *current = head;
        while (current)
        {
            if (current->orderID == orderID)
            {
                cout << "Order " << orderID << " found in history." << endl;
                return true;
            }
            current = current->next;
        }
        cout << "Order " << orderID << " not found in history." << endl;
        return false;
    }

    void showAllPastOrders()
    {
        if (!head)
        {
            cout << "Order history is empty." << endl;
            return;
        }
        cout << "All Past Orders: ";
        Node *current = head;
        while (current)
        {
            cout << current->orderID << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedList()
    {
        Node *current = head;
        while (current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};

queue<int> orderQueue;
stack<int> packingStack;
LinkedList orderHistory;

//Queue functions (Order Queue)

void addOrderToQueue(int orderID)
{
    orderQueue.push(orderID);
    cout << "Order " << orderID << " added to the queue." << endl;
}

int processNextOrder()
{
    if (!orderQueue.empty())
    {
        int order = orderQueue.front();
        orderQueue.pop();
        cout << "Processing Order " << order << " from the queue." << endl;
        return order;
    }
    cout << "No orders to process in the queue." << endl;
    return -1;
}

void showPendingOrders()
{
    if (orderQueue.empty())
    {
        cout << "No pending orders in the queue." << endl;
        return;
    }

    queue<int> tempQueue = orderQueue;
    cout << "Pending Orders in Queue: ";
    while (!tempQueue.empty())
    {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;
}


//Stack functions (Order Packing)

void addItemToPackingStack(int itemID)
{
    packingStack.push(itemID);
    cout << "Item " << itemID << " added to the packing stack." << endl;
}

void undoLastItemPacked()
{
    if (!packingStack.empty())
    {
        int removedItem = packingStack.top();
        packingStack.pop();
        cout << "Undid last packed item: " << removedItem << endl;
    }
    else
    {
        cout << "No items to undo in the packing stack." << endl;
    }
}

void showPackingList()
{
    if (packingStack.empty())
    {
        cout << "Packing stack is empty." << endl;
        return;
    }

    stack<int> tempStack = packingStack;
    cout << "Packing List (from last packed to first): ";
    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
}

int main()
{
    // Stage 1
    cout << "STAGE: 1" << endl; 
    addOrderToQueue(101);
    addOrderToQueue(102);
    addOrderToQueue(103);
    showPendingOrders();
    int orderToPack = processNextOrder();
    int orderToPack2 = processNextOrder();
    cout << endl;

    // Stage 2
    cout << "STAGE: 2" << endl; 
    if (orderToPack != -1 && orderToPack2 != -1)
    {
        addItemToPackingStack(orderToPack);
        showPackingList();
        undoLastItemPacked();
        showPackingList();

        addItemToPackingStack(orderToPack2);
        showPackingList();
        undoLastItemPacked();
        showPackingList();
        cout << endl;
    }

    // Stage 3
    cout << "STAGE: 3" << endl; 
    orderHistory.addOrder(orderToPack);
    orderHistory.addOrder(orderToPack2);
    orderHistory.showAllPastOrders();
    orderHistory.retrieveOrderByID(101);

    return 0;
}
