#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }
    void display(){
        cout<<this->data<<endl;
        cout<<this->next<<endl;
    }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

int main()
{
    Node* node = new Node(10);
    node->display();

    return 0;
}