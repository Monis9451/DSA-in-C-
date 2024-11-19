#include <iostream>
using namespace std;

class Patient
{
public:
    int ID;
    int age;
    string name;
    Patient *left;
    Patient *right;

    Patient(int ID, string name, int age)
    {
        this->name = name;
        this->ID = ID;
        this->age = age;
        left = right = nullptr;
    }
};

Patient *insertingID(Patient *root, Patient *New1)
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
        root->right = insertingID(root->right, New1);
    }
    else
    {
        root->left = insertingID(root->left, New1);
    }
}

void preorder(Patient *root)
{
    if (root)
    {
        cout << root->ID << " " << root->name << ", ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Patient *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->ID << " " << root->name << ", ";
        inorder(root->right);
    }
}

void postorder(Patient *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->ID << " " << root->name << ", ";
    }
}

Patient *search(Patient *root, int ID)
{
    if (!root || root->ID == ID)
        return root;
    if (root->ID < ID)
        return search(root->right, ID);
    return search(root->left, ID);
}

Patient *maxAge(Patient *root, Patient* Maxaged)
{
    if (!root)
        return Maxaged;
    if (root->age > Maxaged->age)
        Maxaged = root;
    Patient *left = maxAge(root->left, Maxaged);
    Patient *right = maxAge(root->right, Maxaged);
    if (left->age > right->age)
        return left;
    return right;
}

void Deletion(Patient*& root, int ID)
{
    if(!root)
    {
        return;
    }
    if(root->ID == ID)
    { 
        if(!root->left && !root->right)
        {
            delete root;
            root = nullptr;
            return;
        }
        if(!root->left)
        {
            Patient* temp = root;
            root = root->right;
            delete temp;
            return;
        }
        if(!root->right)
        {
            Patient* temp = root;
            root = root->left;
            delete temp;
            return;
        }
        Patient* temp = root->right;
        while(temp->left)
            temp = temp->left;
        root->ID = temp->ID;
        root->name = temp->name;
        root->age = temp->age;
        Deletion(root->right, temp->ID);
    }
    if(root->ID < ID)
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

    Patient *root = new Patient(50, "Monis", 18);
    Patient *Ali = new Patient(30, "Ali", 19);
    Patient *Asad = new Patient(20, "Asad", 20);
    Patient *Umer = new Patient(40, "Umer", 21);
    Patient *Bilal = new Patient(70, "Bilal", 22);
    Patient *Mohsin = new Patient(60, "Mohsin", 23);
    Patient *Faizan = new Patient(80, "Faizan", 24);
    root = insertingID(root, Ali);
    root = insertingID(root, Asad);
    root = insertingID(root, Umer);
    root = insertingID(root, Bilal);
    root = insertingID(root, Mohsin);
    root = insertingID(root, Faizan);

    // searching Bilal
    Patient *searched = search(root, 70);
    cout << "Searched: " << searched->ID << ", " << searched->name << endl;

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
    Patient* Maxaged = root;
    Patient *Maxage = maxAge(root, Maxaged);
    cout << "Maximum age: " << Maxage->name << ", " << Maxage->age << ", " << Maxage->ID << endl;

    //deletion
    Deletion(root, 30);
    
    // Print inorder traversal of the BST
    cout << "Inorder: ";
    inorder(root);

    return 0;
}