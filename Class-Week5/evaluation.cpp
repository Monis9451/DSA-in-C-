#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class stack
{
public:
    Node *head = nullptr;

    bool isEmpty()
    {
        return (!head);
    }

    bool push(char data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            return true;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            return true;
        }
    }

    char pop()
    {
        Node *value;
        if (!head)
        {
            return '\0';
        }
        else
        {
            value = head;
            head = head->next;
            char data = value->data;
            delete[] value;
            return data;
        }
    }

    char top()
    {
        if (!head)
        {
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << "|" << temp->data << "|" << endl;
            temp = temp->next;
        }
        cout << "--" << endl;
    }

    int Size()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            Node *temp = head;
            int size = 0;
            while (temp)
            {
                size++;
                temp = temp->next;
            }
            return size;
        }
    }

    bool isOperator(char data)
    {
        return (data == '^' || data == '*' || data == '/' || data == '%' || data == '-' || data == '+');
    }

    int evaluation(string prefix)
    {
        stack Stack;
        for (int i = prefix.size(); i >= 0; i--)
        {
            if (prefix[i] >= '0' && prefix[i] <= '9')
            {
                Stack.push(prefix[i] - '0');
            }
            else
            {
                int a = Stack.pop();
                int b = Stack.pop();
                switch (prefix[i])
                {
                case '+':
                    Stack.push(b + a);
                    break;
                case '-':
                    Stack.push(b - a);
                    break;
                case '*':
                    Stack.push(b * a);
                    break;
                case '/':
                    Stack.push(b / a);
                    break;
                case '%':
                    Stack.push(b % a);
                    break;
                case '^':
                    Stack.push(b ^ a);
                    break;
                }
            }
        }
        return Stack.pop();
    }
};

int main()
{
    stack Stack;

    string prefix = "*+72+38";
    cout << Stack.evaluation(prefix);

    return 0;
}