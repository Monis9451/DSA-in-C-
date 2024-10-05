#include <iostream>
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

    int checkPrecedence(char a)
    {
        switch (a)
        {
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '-':
        case '+':
            return 1;
        default:
            return 0;
        }
    }

    string postfixConverter(char arr[], int size)
    {
        string answer;
        for (int i = 0; i < size; i++)
        {
            if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= '0' && arr[i] <= '9'))
            {
                answer += arr[i];
            }
            else if (arr[i] == '(')
            {
                push(arr[i]);
            }
            else if (arr[i] == ')')
            {
                while (!isEmpty() && top() != '(')
                {
                    answer += pop();
                }
                pop();
            }
            else
            {
                while(!isEmpty() && checkPrecedence(top()) >= checkPrecedence(arr[i]))
                {
                    answer += pop();
                }
                push(arr[i]);
            }
        }
        while(!isEmpty())
        {
            answer += pop();
        }
        return answer;
    }
};

int main()
{
    stack Stack;

    const int size = 11;
    char arr[size] = {'(', 'A', '+', 'B', ')', '*', '(', 'C', '+', 'D', ')'};
    cout << Stack.postfixConverter(arr, size);

    return 0;
}