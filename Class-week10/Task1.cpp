#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    int key;
    int age;
    string name;
    Node *left;
    Node *right;
    Node *parent;

    Node(int ID, string name, int age)
    {
        this->name = name;
        this->key = ID;
        this->age = age;
        left = right = parent = nullptr;
    }
};

Node *insertingID(Node *root, Node *New1)
{
    if (!root)
    {
        root = New1;
        return root;
    }
    if (root->key == New1->key)
    {
        return root;
    }
    if (root->key < New1->key)
    {
        root->right = insertingID(root->right, New1);
        if (root->right) 
            root->right->parent = root;
    }
    else
    {
        root->left = insertingID(root->left, New1);
        if (root->left) root->left->parent = root;
    }
    return root;
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

void preorder(Node *root)
{
    if (root)
    {
        cout << root->key << " " << root->name << ", ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->key << " " << root->name << ", ";
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " " << root->name << ", ";
    }
}

Node *search(Node *root, int ID)
{
    if (!root || root->key == ID)
        return root;
    if (root->key < ID)
        return search(root->right, ID);
    return search(root->left, ID);
}

Node *maxAge(Node *root, Node* Maxaged)
{
    if (!root)
        return Maxaged;
    if (root->age > Maxaged->age)
        Maxaged = root;
    Node *left = maxAge(root->left, Maxaged);
    Node *right = maxAge(root->right, Maxaged);
    if (left->age > right->age)
        return left;
    return right;
}

void Deletion(Node*& root, int ID)
{
    if(!root)
    {
        return;
    }
    if(root->key == ID)
    { 
        if(!root->left && !root->right)
        {
            if(root->parent->left == root)
                root->parent->left = nullptr;
            else
                root->parent->right = nullptr;
            delete root;
            return;
        }
        if(!root->left)
        {
            root->parent->right = root->right;
            delete root;
            return;
        }
        if(!root->right)
        {
            root->parent->left = root->left;
            delete root;
            return;
        }
        Node* temp = root->right;
        while(temp->left)
            temp = temp->left;
        root->key = temp->key;
        root->name = temp->name;
        root->age = temp->age;
        Deletion(root->right, temp->key);
        if (root->right)
            root->right->parent = root;
    }
    if(root->key < ID)
    {
        Deletion(root->right, ID);
    }
    else
    {
        Deletion(root->left, ID);
    }
}

void descendingOrder(Node *root, stack<int> &st)
{
    if (root)
    {
        descendingOrder(root->right, st);
        cout << root->key << " " << root->name << ", ";
        descendingOrder(root->left, st);
    }
}

int height(Node* root)
{
    if(!root)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}

void levelOrderDisaply(Node* root)
{
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout << temp->key << " " << temp->name << ", ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

int main()
{
    Node *root = new Node(5, "Monis", 18);
    Node *Ali = new Node(2, "Ali", 19);
    Node *Asad = new Node(18, "Asad", 20);
    Node *Umer = new Node(-4, "Umer", 21);
    Node *Bilal = new Node(3, "Bilal", 22);
    Node *Mohsin = new Node(21, "Mohsin", 23);
    Node *Faizan = new Node(19, "Faizan", 24);
    Node *Hamza = new Node(25, "Hamza", 26);
    root = insertingID(root, Ali);
    root = insertingID(root, Asad);
    root = insertingID(root, Umer);
    root = insertingID(root, Bilal);
    root = insertingID(root, Mohsin);
    root = insertingID(root, Faizan);
    root = insertingID(root, Hamza);

    // searching Bilal
    Node *searched = search(root, 21);
    cout << "Searched: " << searched->key << ", " << searched->name << endl;

    // Print inorder traversal of the BST
    cout << "Inorder: ";
    inorder(root);

    // order
    cout << "Which order you want to display?" << endl;
    cout << "1.Preorder" << endl;
    cout << "2.Inorder/ Acsending order" << endl;
    cout << "3.Postorder" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Preorder: ";
        preorder(root);
        break;
    case 2:
        cout << "Inorder: ";
        inorder(root);
        break;
    case 3:
        cout << "Postorder: ";
        postorder(root);
        break;
    default:
        cout << "Enter a right option" << endl;
    }
    cout << endl;
    
    // maximum age
    Node* Maxaged = root;
    Node *Maxage = maxAge(root, Maxaged);
    cout << "Maximum age: " << Maxage->name << ", " << Maxage->age << ", " << Maxage->key << endl;

    //deletion
    Deletion(root, 21);
    
    // Print inorder traversal of the BST
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    // descending order
    stack<int> st;
    cout << "Descending order: ";
    descendingOrder(root, st);
    cout << endl;

    //Height
    cout << "Height of the tree: " << height(root) << endl;

    //Level order display
    cout << "Level order display: ";
    levelOrderDisaply(root);
    cout << endl;

    return 0;
}