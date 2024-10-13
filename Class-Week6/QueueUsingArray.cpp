#include <iostream>
using namespace std;
#define MAX_SIZE 10

class Queue
{
public:
    int queue[MAX_SIZE];
    int front = 0;
    int rear = 0;
    int currSize = 0;

    bool isEmpty()
    {
        if (currSize == 0)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (currSize == MAX_SIZE)
        {
            return true;
        }
        return false;
    }

    int size()
    {
        return currSize;
    }

    bool enqueue(int data)
    {
        if (isEmpty())
        {
            queue[front] = data;
            currSize++;
            return true;
        }
        else if (isFull())
        {
            return false;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
            queue[rear] = data;
            currSize++;
            return true;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            int toReturn = queue[front];
            front = (front + 1) % MAX_SIZE;
            currSize--;
            return toReturn;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: " << endl;
        for (int i = 0; i < currSize; i++)
        {
            int index = (front + i) % MAX_SIZE;
            cout << "|" << queue[index] << "|" << endl;
        }
        cout << endl;
    }
};

int main()
{
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    queue.enqueue(10);
    queue.display();
    cout << "Size: " << queue.size() << endl;
    cout << "Deque: " << queue.dequeue() << endl;
    cout << "Size: " << queue.size() << endl;
    cout << "Deque: " << queue.dequeue() << endl;
    cout << "Size: " << queue.size() << endl;
    queue.display();
    queue.enqueue(11);
    queue.display();

    return 0;
}