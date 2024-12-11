#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int balance;

    Node(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr), balance(0) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        if (T2 != nullptr) T2->parent = y;
        x->parent = y->parent;
        y->parent = x;

        y->balance = getBalance(y);
        x->balance = getBalance(x);

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        if (T2 != nullptr) T2->parent = x;
        y->parent = x->parent;
        x->parent = y;

        x->balance = getBalance(x);
        y->balance = getBalance(y);

        return y;
    }

    Node* rightRightRotate(Node* y) {
        return rightRotate(y);
    }

    Node* leftLeftRotate(Node* x) {
        return leftRotate(x);
    }

    Node* rightLeftRotate(Node* x) {
        x->right = rightRotate(x->right);
        return leftRotate(x);
    }

    Node* leftRightRotate(Node* y) {
        y->left = leftRotate(y->left);
        return rightRotate(y);
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr) return new Node(key);

        if (key < node->data) {
            node->left = insert(node->left, key);
            node->left->parent = node;
        } else if (key > node->data) {
            node->right = insert(node->right, key);
            node->right->parent = node;
        } else {
            return node;
        }

        node->balance = getBalance(node);

        if (node->balance > 1 && key < node->left->data) {
            return rightRightRotate(node);
        }

        if (node->balance < -1 && key > node->right->data) {
            return leftLeftRotate(node);
        }

        if (node->balance > 1 && key > node->left->data) {
            return leftRightRotate(node);
        }

        if (node->balance < -1 && key < node->right->data) {
            return rightLeftRotate(node);
        }

        return node;
    }

    void preOrder(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == nullptr)
            return root;

        root->balance = getBalance(root);

        if (root->balance > 1 && getBalance(root->left) >= 0)
            return rightRightRotate(root);

        if (root->balance > 1 && getBalance(root->left) < 0) {
            root->left = leftLeftRotate(root->left);
            return rightRightRotate(root);
        }

        if (root->balance < -1 && getBalance(root->right) <= 0)
            return leftLeftRotate(root);

        if (root->balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRightRotate(root->right);
            return leftLeftRotate(root);
        }

        return root;
    }

public:
    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void preOrder() {
        preOrder(root);
    }
};

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Preorder traversal of the constructed AVL tree is \n";
    tree.preOrder();

    return 0;
}