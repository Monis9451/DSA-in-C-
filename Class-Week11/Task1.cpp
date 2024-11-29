#include <iostream>
#include <stack>
using namespace std;
class Node
{
public:
    int ID;
    string name;
    int age;
    Node *right;
    Node *left;
    Node *parent;

    Node(int data, string name, int age)
    {
        ID = data;
        this->name = name;
        this->age = age;
        right = left = parent = nullptr;
    }
};

Node *insertion(Node *root, Node *New1)
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
    if (root->ID < New1->ID)
    {
        root->right = insertion(root->right, New1);
        if (root->right)
            root->right->parent = root;
    }
    else
    {
        root->left = insertion(root->left, New1);
        if (root->left)
            root->left->parent = root;
    }
    return root;
}

Node *search(Node *root, int ID)
{
    if (root->ID == ID)
        return root;
    if (root->ID < ID)
        return search(root->right, ID);
    else
        return search(root->left, ID);
}

void Deletion(Node *root, int ID)
{
    Node *toDel = search(root, ID);
    if (!toDel->left && !toDel->right)
    {
        if (toDel->parent->left == toDel)
            toDel->parent->left = nullptr;
        else
            toDel->parent->right = nullptr;
        delete toDel;
    }
    if (!toDel->left && toDel->right)
    {
        if (toDel->parent->left == toDel)
            toDel->parent->left = toDel->right;
        else
            toDel->parent->right = toDel->right;
        toDel->right->parent = toDel->parent;
        delete toDel;
    }
    if (toDel->left && !toDel->right)
    {
        if (toDel->parent->left == toDel)
            toDel->parent->left = toDel->left;
        else
            toDel->parent->right = toDel->left;
        toDel->left->parent = toDel->parent;
        delete toDel;
    }
    if (toDel->left && toDel->right)
    {
        Node *temp = toDel->right;
        while (temp->left)
            temp = temp->left;
        toDel->ID = temp->ID;
        toDel->name = temp->name;
        toDel->age = temp->age;
        Deletion(toDel->right, temp->ID);
    }
}

void InOrder(Node *root)
{
    if (!root)
        return;
    InOrder(root->left);
    cout << root->ID << " " << root->name << " " << root->age << endl;
    InOrder(root->right);
}

void sortingDescending(Node *root)
{
    if (!root)
        return;
    sortingDescending(root->right);
    cout << root->ID << " " << root->name << " " << root->age << endl;
    sortingDescending(root->left);
}

int Height(Node *root)
{
    if (!root)
        return 1;
    int lHeight = Height(root->left);
    int rHeight = Height(root->right);
    if (rHeight > lHeight)
        return (rHeight + 1);
    return (lHeight + 1);
}

void currentLvl(Node* root, int level)
{
    if(!root)
     return;
    if (level == 1)
        cout << root->ID << " ";
    else if (level > 1) {
        currentLvl(root->left, level - 1);
        currentLvl(root->right, level - 1);
    }
}

void levelOrder(Node *root)
{
    int height = Height(root);
    for (int i = 0; i < height; i++)
    {
        currentLvl(root, i);
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(50, "Ali", 25);
    insertion(root, new Node(30, "Ahmed", 20));
    insertion(root, new Node(20, "Omar", 30));
    insertion(root, new Node(40, "Sara", 35));
    insertion(root, new Node(70, "Nada", 40));
    insertion(root, new Node(60, "Ahmad", 45));
    insertion(root, new Node(80, "Zainab", 50));
    insertion(root, new Node(90, "Bilal", 55));
    insertion(root, new Node(85, "Hamza", 60));
    insertion(root, new Node(95, "Umer", 65));
    insertion(root, new Node(75, "Amir", 70));
    insertion(root, new Node(65, "Talha", 75));
    insertion(root, new Node(45, "Yasir", 80));
    insertion(root, new Node(35, "Salman", 85));
    insertion(root, new Node(25, "Khadija", 90));
    // InOrder(root);
    // Deletion(root, 95);
    cout << endl;
    InOrder(root);
    cout << endl;
    sortingDescending(root);
    cout << endl;
    cout << Height(root) << endl;
    levelOrder(root);

    return 0;
}
