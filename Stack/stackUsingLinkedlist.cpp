#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *next;

    Node(int val)
    {
        this->key = val;
        this->next = nullptr;
    }
};

class Stack
{
public:
    Node *top = nullptr;

    //------------Pushing value in stack-----------
    void push(int val)
    {
        if (isEmpty())
        {
            top = new Node(val);
        }
        else
        {
            Node *temp = new Node(val);
            temp->next = top;
            top = temp;
        }
    }

    //------------Pushing value in stack-----------
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        Node *toDel = top;
        top = top->next;
        delete toDel;
    }

    //------------Checking the top value of stack-----------
    int topVal()
    {
        if (isEmpty())
        {
            return -111;
        }
        else
        {
            return top->key;
        }
    }

    //------------Checking the stack size-----------
    int stackSize()
    {
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            Node *temp = top;
            int counter = 0;
            while (temp != nullptr)
            {
                temp = temp->next;
                counter++;
            }
            return counter;
        }
    }

    //------------Checking for empty stack-----------
    bool isEmpty()
    {
        return top == nullptr;
    }

    //------------Checking for empty stack-----------
    void printStack()
    {
        if (isEmpty())
        {
            cout << "The stack is empty" << endl;
        }
        else
        {
            Node *temp = top;
            while (temp != nullptr)
            {
                cout << "|" << temp->key << "|" << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{ 
    Stack stack;
    cout << "Pushing some data" << endl;
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    cout << "Printing data" << endl;
    stack.printStack();
    cout << "Pop the last value" << endl;
    stack.pop();
    cout << "Printing data" << endl;
    stack.printStack();
    cout << "Printing top value" << endl;
    cout << stack.topVal() << endl;
    cout << "Printing size of stack" << endl;
    cout << stack.stackSize() << endl;
    return 0;
}