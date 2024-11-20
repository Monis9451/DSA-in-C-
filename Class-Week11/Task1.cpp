#include <iostream>
using namespace std;
class Node
{
    public:
    int ID;
    string name;
    int age;
    Node* right;
    Node* left;
    Node* parent;

    Node(int data,string name, int age)
    {
        ID = data;
        this->name = name;
        this->age = age;
        right = left = parent = nullptr;
    }
};

Node* insertion(Node* root, Node* New1)
{
    if (!root)
    {
        root = New1;
        return root;
    }
    if (root->ID == New1->ID)
    {
        return root;
    }
    if (root->key < New1->key)
    {
        root->right = insertingID(root->right, New1);
    }
    else
    {
        root->left = insertingID(root->left, New1);
    }
}




