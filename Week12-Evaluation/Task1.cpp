#include <iostream>
using namespace std;

struct Bnode
{
    int key;
    Bnode *left;
    Bnode *right;
    Bnode(int key)
    {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void modifiedBST(Bnode *root, int &sum)
{
    if (!root)
        return;

    modifiedBST(root->right, sum);

    sum += root->key;
    root->key = sum;

    modifiedBST(root->left, sum);
}

void inorder(Bnode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main()
{
    Bnode *root = new Bnode(50);
    root->left = new Bnode(30);
    root->right = new Bnode(70);
    root->left->left = new Bnode(20);
    root->left->right = new Bnode(40);
    root->right->left = new Bnode(60);
    root->right->right = new Bnode(80);

    cout << "Original inorder tree: ";
    inorder(root);
    cout << endl;

    int sum = 0;
    modifiedBST(root, sum);


    cout << "Modified inorder tree: ";
    inorder(root);
    return 0;
}
