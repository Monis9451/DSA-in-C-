#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int key)
    {
        this->key = key;
        left = right = nullptr;
    }
};

Node *insertingID(Node *root, int key)
{
    if (!root)
    {
        return new Node(key);
    }
    if (root->key < key)
    {
        root->right = insertingID(root->right, key);
    }
    else
    {
        root->left = insertingID(root->left, key);
    }
    return root;
}

void preorder(Node *root)
{
    if (root)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->key << ", ";
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

Node *search(Node *root, int key)
{
    if (!root || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

void Deletion(Node *&root, int key)
{
    if (!root)
    {
        return;
    }
    if (root->key == key)
    {
        if (!root->left && !root->right)
        {
            delete root;
            root = nullptr;
            return;
        }
        if (!root->left)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
            return;
        }
        if (!root->right)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
            return;
        }
        Node *temp = root->right;
        while (temp->left)
            temp = temp->left;
        root->key = temp->key;
        Deletion(root->right, temp->key);
    }
    if (root->key < key)
    {
        Deletion(root->right, key);
    }
    else
    {
        Deletion(root->left, key);
    }
}

Node *Minimum(Node *root)
{
    while (root->left)
        root = root->left;
    return root;
}

Node *Maximum(Node *root)
{
    while (root->right)
        root = root->right;
    return root;
}

int Floor(Node *root, int x)
{
    if (!root)
        return -1;
    if (root->key == x)
        return root->key;
    if (root->key > x)
        return Floor(root->left, x);
    int floorValue = Floor(root->right, x);
    return (floorValue <= x && floorValue != -1) ? floorValue : root->key;
}

int main()
{
    // 50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85
    Node *root = nullptr;
    root = insertingID(root, 50);
    root = insertingID(root, 30);
    root = insertingID(root, 70);
    root = insertingID(root, 20);
    root = insertingID(root, 40);
    root = insertingID(root, 60);
    root = insertingID(root, 80);
    root = insertingID(root, 10);
    root = insertingID(root, 25);
    root = insertingID(root, 35);
    root = insertingID(root, 45);
    root = insertingID(root, 55);
    root = insertingID(root, 65);
    root = insertingID(root, 75);
    root = insertingID(root, 85);

    // Inorder traversal: 10, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85
    cout << "Should be:      10, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85" << endl;

    // Print inorder traversal of the BST
    cout << "Actual Inorder: ";
    inorder(root);
    cout << endl;

    // Printing the minimum
    cout << "Minimum:        " << Minimum(root)->key << endl;

    // Printing the maximum
    cout << "Maximum:        " << Maximum(root)->key << endl;

    //Finding floor
    cout << "Floor for 68 :  " << Floor(root, 68);

    return 0;
}