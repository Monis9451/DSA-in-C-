#include <iostream>
using namespace std;
#define Size 20

class Queue
{
private:
    int item[Size], front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        if (front == 0 && rear == Size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if(front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //------------inserted a new item------------
    void enQueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front++;
            }
            rear++;
            item[rear] = val;
            cout << "New value inserted" << endl;
        }
    }

    //------------deleted the first item------------
    int deQueue()
    {
        int element;
        if (isEmpty())
        {
            cout << "The Queue is empty" << endl;
            return -1;
        }
        else
        {
            element = item[front];
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front++;
            }
            cout << "Deleted ->" << element << endl;
            return element;
        }
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout<<"Front index -> "<< front << endl;
            cout<<"Items -> "<<endl;
            for(int i=0;i<=rear;i++)
            {
                cout<<item[i]<<endl;
            }
            cout<<"Rear index -> "<< rear << endl;
        }
    }
};

int main()
{
    Queue queue;
    queue.enQueue(5);
    queue.enQueue(6);
    queue.enQueue(7);
    queue.enQueue(8);
    queue.print();
    cout<<queue.deQueue()<<endl;
    queue.print();

    return 0;
}