#include <iostream>
using namespace std;
#define n 50

class Stack
{
public:
    int arr[n];
    int top = -1;

    //----------------pushing a value in stack-----------
    void push(int val)
    {
        if (isFull())
        {
            cout << "The stack is full" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    //----------------poping last value of stack-----------
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        arr[top] = 0;
        top--;
    }

    //----------------poping last value of stack-----------
    int popReturnVal()
    {
        if (isEmpty())
        {
            cout << "The stack is empty" << endl;
            return -1111;
        }
        int toReturn = arr[top];
        arr[top] = 0;
        top--;
        return toReturn;
    }

    //----------------Printing stack------------------------
    void print()
    {
        if (isEmpty())
        {
            cout << "There is nothing to print, the stack is empty" << endl;
            return;
        }
        for (int i = 0; i <= top; i++)
        {
            cout << "|" << arr[i] << "|" << endl;
        }
        cout << endl;
    }

    //----------------Getting top value of stack------------
    int topVal()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1111;
        }
        return arr[top];
    }

    //----------------Getting stack size--------------------
    int stackSize()
    {
        return top + 1;
    }

    //----------------Checking stack, is it full?-----------
    bool isFull()
    {
        return (top + 1 == n);
    }

    //----------------Checking stack, is it empty?-----------
    bool isEmpty()
    {
        return (top == -1);
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
    stack.print();
    cout << "Pop the last value" << endl;
    stack.pop();
    cout << "Printing data" << endl;
    stack.print();
    cout << "Printing pop data" << endl;
    cout << stack.popReturnVal() << endl;
    cout << "Printing data" << endl;
    stack.print();
    cout << "Printing top value" << endl;
    cout << stack.topVal() << endl;
    cout << "Printing size of stack" << endl;
    cout << stack.stackSize() << endl;

    return 0;
}