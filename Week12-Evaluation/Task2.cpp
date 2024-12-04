#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;

    Node(int data)
    {
        this->key = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *newNode(int data)
{
    return new Node(data);
}

int maxSum(Node *node, int &res)
{
    if (node == nullptr)
        return 0;

    int left = maxSum(node->left, res);
    int right = maxSum(node->right, res);

    res = max(res, node->key + max(left, right));

    return node->key + max(left, right);
}

int maxSumPath(Node *root)
{
    if (root == nullptr)
        return 0;

    int max = 0;
    maxSum(root, max);
    return max;
}

int main()
{
    Node *root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->left->right = newNode(5);

    cout << "Maximum sum path from leaf to root is: " << maxSumPath(root) << endl;

    return 0;
}