#include<iostream>
#include<queue>
using namespace std;

class Node {
public:

	int num;
	Node* parent;
	Node* left;
	Node* right;
	
	Node() {
		num = -404;
		parent = left=right=nullptr;
	}
	Node(int a) {
		num = a;
		parent = left = right = nullptr;
	}
	Node(int a, Node* l,Node* r) {
		num = -404;
		right = r; left = l; parent = nullptr;
	}
	Node(int a, Node* l, Node* r,Node* p) {
		num = -404;
		right = r; left = l; parent = p;
	}

};

class Tree {
	
public:
	Node* roott;
	Tree():roott(nullptr){}
	Node* insert(Node* root,int val) {
		if (!root) return new Node(val);
		
		if (root->num > val) {
			Node* ns = insert(root->left, val);
			root->left = ns;
			ns->parent = root;
		}
		else if (root->num < val) {
			Node* ns = insert(root->right, val);
			root->right = ns;
			ns->parent = root;
		}
		else if (root->num == val)
		{
			cout << "\nNot possible value exists";
		}
		return root;
	}
	void inorder(Node* p) {
		if (p) {
			inorder(p->left);
			cout << p->num<<" ";
			inorder(p->right);
		
		}
	}
	void sorting(Node* p) {
		if (p) {
			inorder(p->right);
			cout << p->num << " ";
			inorder(p->left);
		}
	}
	void levelOrder() {
		if (!roott) return;

		queue<Node*> q;
		q.push(roott);

		while (!q.empty()) {
			Node* n2 = q.front();
			q.pop();
			cout << n2->num << " ";
			if (n2->left) q.push(n2->left);
			if (n2->right) q.push(n2->right);

		}
	}
	int maxDepth(Node* node) {
		if (node == nullptr)
			return 0;

		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		return max(lDepth, rDepth) ;


	}

	void deleteNode(Node* root, int val) {
		Node* del = search(root, val);
		Node* par = del->parent;
		if (!isleaf(del)) {
			
			
			if (par->left == del) {
				par->left = nullptr;
			}else{
				par->right = nullptr;
			}
			delete del;
			return;
		}
		else if (twoChild(del)) {
			Node* gladiator = inOrderSuccessor(del->right);
			swap(del->num, gladiator->num);
			deleteNode(root, val);
			return;
		}
		else {
			Node* temp;
			if (par->left == del) {
				par->left = del->left ? del->left : del->right;
			}else  {
				par->right = del->left ? del->left : del->right;
			}
			delete del;
			return;
		}

	}
	Node* inOrderSuccessor(Node* ptr){
		if (!ptr) return nullptr;
		if (!ptr->left) return ptr;
		return inOrderSuccessor(ptr->left);
	}
	bool twoChild(Node* ptr){
	return  ptr->left && ptr->right;
	}
	bool isleaf(Node* ptr) {
		return ptr->left || ptr->right;
	}
	Node* search(Node*p,int val) {
		if (p) {
			if (p->num == val) return p;

			if (p->num > val) {
				return search(p->left, val);
			}
			if (p->num < val) {
				return search(p->right, val);
			}
		}
	}


};



int main() {

	// Tree t;
	// t.insert()
	// t.insert()
	// t.insert()
	// t.insert()
	// t.insert()
	// t.insert()
	// t.insert()
	// t.insert()
	// t.insert()
	// t.insert()
	// t.insert()

	Tree t;
	int x = 10;
	while (x--) {
		cout << "\nEnter value : ";
		int num;
		cin >> num;
		t.roott=t.insert(t.roott, num);
		cout << endl;
		t.inorder(t.roott);
		cout << endl;
		t.levelOrder();
	}
	cout<<t.maxDepth(t.roott);
    
}