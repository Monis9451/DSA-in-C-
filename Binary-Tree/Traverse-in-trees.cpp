#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void inorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    }

class tree
{
public:
    Node *root;

    tree()
    {
        root = nullptr;
    }

    int height(Node *root)
    {
        if (!root)
            return 0;
        else
        {
            int lheight = height(root->left);
            int rheight = height(root->right);
            return (lheight > rheight) ? lheight + 1 : rheight + 1;
        }
    }

    void preOrder(Node *root)
    {
        if (root == nullptr)
            return;

        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node *root)
    {
        if (root == nullptr)
            return;

        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void postOrder(Node *root)
    {
        if (root == nullptr)
            return;

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
};

int main()
{
    tree tree1;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;
    node5->left = node7;
    cout << "Traversing preorder" << endl;
    tree1.preOrder(node1);
    cout << endl;
    cout << "Traversing inorder" << endl;
    tree1.inOrder(node1);
    cout << endl;
    cout << "Traversing postorder" << endl;
    tree1.postOrder(node1);
    cout << endl;
    cout << "Height of tree" << endl;
    cout << tree1.height(node1) << endl;

    return 0;
}