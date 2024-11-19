#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int age;
    string name;
    Node *left;
    Node *right;

    Node(int ID, string name, int age)
    {
        this->name = name;
        this->key = ID;
        this->age = age;
        left = right = nullptr;
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
            delete root;
            root = nullptr;
            return;
        }
        if(!root->left)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
            return;
        }
        if(!root->right)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
            return;
        }
        Node* temp = root->right;
        while(temp->left)
            temp = temp->left;
        root->key = temp->key;
        root->name = temp->name;
        root->age = temp->age;
        Deletion(root->right, temp->key);
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

int main()
{
    // Creating the following BST
    //               50(Monis)
    //             /           \
    //      30(Ali)              70(Bilal)
    //      /     \              /      \
    //  20(Asad) 40(Umer)   60(Mohsin) 80(Faizan)

    Node *root = new Node(50, "Monis", 18);
    Node *Ali = new Node(30, "Ali", 19);
    Node *Asad = new Node(20, "Asad", 20);
    Node *Umer = new Node(40, "Umer", 21);
    Node *Bilal = new Node(70, "Bilal", 22);
    Node *Mohsin = new Node(60, "Mohsin", 23);
    Node *Faizan = new Node(80, "Faizan", 24);
    root = insertingID(root, Ali);
    root = insertingID(root, Asad);
    root = insertingID(root, Umer);
    root = insertingID(root, Bilal);
    root = insertingID(root, Mohsin);
    root = insertingID(root, Faizan);

    // searching Bilal
    Node *searched = search(root, 70);
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
    Deletion(root, 30);
    
    // Print inorder traversal of the BST
    cout << "Inorder: ";
    inorder(root);

    return 0;
}