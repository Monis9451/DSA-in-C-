// #include <iostream>
// using namespace std;

// void towerOfHanoi(int n, int start, int end) {
//     if (n == 0) return;

//     int aux = 6 - start - end; // Sum of rods is 6 (1 + 2 + 3), so this gives the auxiliary rod.
    
//     towerOfHanoi(n - 1, start, aux);  // Move n-1 disks from start to auxiliary
//     cout << "Move disk " << n << " from rod " << start << " to rod " << end << endl;
//     towerOfHanoi(n - 1, aux, end);    // Move n-1 disks from auxiliary to end
// }

// int main() {
//     int n;
//     cout << "Enter the number of disks: ";
//     cin >> n;
//     towerOfHanoi(n, 1, 3); // 1 is the starting rod, 3 is the ending rod
//     return 0;
// }


// #include <iostream>
// #include <climits>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node(int value) : data(value), next(nullptr) {}
// };

// int findMax(Node* head) {
//     // Base case: if the list is empty, return the smallest integer as a default
//     if (head == nullptr) {
//         return INT_MIN;
//     }
//     // Recursive case: find the maximum in the rest of the list
//     int maxInRest = findMax(head->next);
    
//     // Return the maximum of the current node's data and the max in the rest
//     return max(head->data, maxInRest);
// }

// int main() {
//     // Example linked list creation
//     Node* head = new Node(1);
//     head->next = new Node(3);
//     head->next->next = new Node(5);
//     head->next->next->next = new Node(2);

//     int maxValue = findMax(head);
//     cout << "The greatest value in the list is: " << maxValue << endl;

//     return 0;
// }

// C++ program for decimal to binary
// conversion using recursion
// #include <iostream>
// using namespace std;

// Decimal to binary conversion
// using recursion
// int find(int decimal_number)
// {
// 	if (decimal_number == 0) 
// 		return 0; 
// 	else
// 		return (decimal_number % 2 + 10 * 
// 				find(decimal_number / 2));
// }

// Driver code 
// int main()
// {
// 	int decimal_number = 10;
// 	cout << find(decimal_number);
// 	return 0;
// }
// This code is contributed by shivanisinghss2110

#include <iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node* left;
	Node* right;
	Node* parent;
	Node(int data)
	{
		this->data = data;
		left = right = parent = nullptr;
	}
};

class Tree
{
	Node* Root;
	Tree()
	{
		Root = nullptr;
	}

	Node* insertion(int data, Node* root)
	{
		if(!root || root->data == data)
		{
			root = new Node(data);
			return root;
		}
		if(root->data < data)
		{
			root->right = insertion(data, root->right);
			if(root->right)
				root->right->parent = root;
		}
		if(root->data > data)
		{
			root->left = insertion(data, root->left);
			if(root->left)
				root->left->parent = root;
		}
		return root;
	}

	Node* search(int data, Node* root)
	{
		if(root->data == data)
			return root;
		if(root->data < data)
			return search(data, root->right);
		else
			return search(data, root->left);
	}

	Node* deletion(int data, Node* root)
	{
		Node* toDel = search(data, root);
		if(!toDel->right && !toDel->left)
		{
			if(toDel->parent->right == toDel)
			toDel->parent->right = nullptr;
			else
			toDel->parent->left = nullptr;
			delete toDel;
		}
		if(!toDel->right && toDel->left)
		{
			if(toDel->parent->right == toDel)
			toDel->parent->right = toDel->left;
			else
			toDel->parent->left = toDel->left;
			toDel->left->parent = toDel->parent;
			delete toDel;
		}
		if(toDel->right && !toDel->left)
		{
			if(toDel->parent->right == toDel)
			toDel->parent->right = toDel->right;
			else
			toDel->parent->left = toDel->right;
			toDel->right->parent = toDel->parent;
			delete toDel;
		}
		if(toDel->right && toDel->left)
		{
			Node* temp = root->right;
			while(temp)
			temp = temp->left;
			toDel->data = temp->data;
			deletion(temp->data, toDel->right);
		}
	}

	int Height(Node* root)
	{
		if(!root)
		return 1;
		int rHeight = Height(root->right);
		int lHeight = Height(root->left);
		if(rHeight > lHeight)
		return rHeight + 1;
		else
		return lHeight + 1;
	}

};