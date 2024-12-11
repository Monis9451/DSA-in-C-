#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
	node* parent;
	node* left;
	node* right;
	int id;
	node(int id)
	{
		parent = NULL;
		left = NULL;
		right = NULL;
		this->id = id;
	}
};
class tree {
private:
	node* root;
public:
	tree()
	{
		root = NULL;
	}
	void set_root(node* root)
	{
		this->root = root;
	}
	node* get_root()
	{
		return root;
	}
	node* insert(int value,node *temp)
	{
		
		if (temp == NULL)
		{
			node* newnode = new node(value);
			return newnode;
		}
		else if (temp->id < value)
		{
			node* newnode = insert(value, temp->right);
			temp->right = newnode;
			newnode->parent = temp;
		}
		else if (temp->id > value)
		{
			node* newnode = insert(value, temp->left);
			temp->left = newnode;
			newnode->parent = temp;
		}
		else if (temp->id == value)
		{
			cout << "Insertion not possible";
			return NULL;
		}
		return temp;
	}
	void display_in_dec(node *temp)
	{
		if (temp != NULL)
		{
			display_in_dec(temp->right);
			cout << temp->id << " ";
			display_in_dec(temp->left);
		}
	}
	bool is_leaf(node* temp)
	{
		if (temp == NULL) 
			return false; 
		return (temp->left == NULL && temp->right == NULL);
	}

	node* min(node* root)
	{
		if (root == NULL)
			return NULL;
		if (root->left == NULL)
		{
			return root;
		}
		return min(root->left);
	}
	node* max1(node* root)
	{
		if (root == NULL)
			return NULL;
		if (root->right == NULL)
		{
			return root;
		}
		return max1(root->right);
	}
	node* search(node* root, int value)
	{
		if (!root)
		{
			return NULL;
		}
		if (root)
		{
			if (root->id == value)
			{
				return root;
			}
			else if (root->id < value)
			{
				return search(root->right, value);
			}
			else if (root->id > value)
			{
				return search(root->left, value);
			}
		}
		return NULL;
	}
	void delete_node(int value, node* temp)
	{ 
		node* del = search(temp,value);
		if (is_leaf(del))
		{
			if (root == del && !root->left && !root->right)
			{
				root = NULL;
			}
			else if (del->parent->left == del)
			{
				del->parent->left = NULL;
			}
			else if (del->parent->right == del)
			{
				del->parent->right = NULL;
			}
			delete del;
		}
		else if ((del->left == NULL && del->right != NULL) || (del->left != NULL && del->right == NULL))
		{
			node* t1=NULL;
			if (del->left == NULL)
				t1 = del->right;
			else if (del->right == NULL)
				t1 = del->left;
			if (del->parent->right == del)
			{
				del->parent->right = t1;
			}
			else if (del->parent->left == del)
			{
				del->parent->left = t1;
			}
			t1->parent = del->parent;
			delete del;
		}
		else if (del->right != NULL && del->left != NULL)
		{
			node* insuc = min(del->right);
			swap(del->id, insuc->id);
			delete_node(value, insuc);
		}
	}
	void level_order()
	{
		queue<node*> q;
		q.push(root);
		while (!q.empty())
		{
			node* temp = q.front();
			q.pop();
			cout << temp->id << " ";
			if (temp->left != NULL)
			{
				q.push(temp->left);
			}
			if (temp->right != NULL)
			{
				q.push(temp->right);
			}
		}
	}
	int left(node* root)
	{
		if (root->left != NULL)
		{
			return 1 + left(root->left);
		}
		return 0;

	}
	int right(node* root)
	{
		if (root->right != NULL)
		{
			return 1 + right(root->right);
		}
		return 0;
	}
	int findHeight(node* root) {
		if (root == nullptr) {
			return -1; // Height of an empty tree is -1
		}
		int leftHeight = findHeight(root->left);
		int rightHeight = findHeight(root->right);
		return max(leftHeight, rightHeight) + 1;
	}
};
int main()
{
	tree t1;
	node* root = t1.insert(50, t1.get_root());
	t1.set_root(root);
	t1.insert(30, t1.get_root());
	t1.insert(70, t1.get_root());
	t1.insert(20, t1.get_root());
	t1.insert(40, t1.get_root());
	t1.insert(10, t1.get_root());
	t1.insert(25, t1.get_root());
	t1.insert(60, t1.get_root());
	t1.insert(80, t1.get_root());
	cout << "Values are inserted";
	cout << endl;
	cout << "Displaying in dec order\n";
	t1.display_in_dec(t1.get_root());
	/*cout << "\nSearching....\n";
	root = t1.search(t1.get_root(), 70);
	cout << root->id;
	cout << endl;*/
	cout << "Delete...\n";
	t1.delete_node(30, t1.get_root());
	cout << "\nDisplaying in dec order\n";
	t1.display_in_dec(t1.get_root());
	cout << "Delete...\n";
	t1.delete_node(70, t1.get_root());
	cout << "\nDisplaying in dec order\n";
	t1.display_in_dec(t1.get_root());
	cout << "Delete...\n";
	t1.delete_node(50, t1.get_root());
	cout << "\nDisplaying in dec order\n";
	t1.display_in_dec(t1.get_root());
	/*cout << endl;
	t1.level_order();
	int h=t1.findHeight(t1.get_root());
	cout << endl << h << endl;*/
	return 0;
}