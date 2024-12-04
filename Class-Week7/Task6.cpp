#include <iostream>
using namespace std;

class Node
{
    public:
    int key;
    Node *next;
    Node(int val) : key(val), next(nullptr) {}
};

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->key << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main()
{

    return 0;
}