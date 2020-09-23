#include<iostream>
#include<cstdlib>

using namespace std;

class node{
friend class BST;
private:
	int data;
	node *left;	
	node *right;	
};

class BST{
public:
	BST();
	void insert_node(int value);
	void print();
private:
	void print_inorder(node *ptr);
	node *root;
};

BST::BST(){
	root = NULL;
}

void BST::insert_node(int value)
{
    node *new_node;
    node *current;
    node *parent;

    new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    if(root == NULL)
    {
        root = new_node; //return new_node;
    }
    else
    {
        current = root;
        while(current != NULL)
        {
            parent = current;
            if(current->data > value)
                current = current->left;
            else
                current = current->right;
        }
        if(parent->data > value)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    //return root;
}

void BST::print(){
	print_inorder(root);
	cout << endl;
}
void BST::print_inorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_inorder(ptr->left);
        //printf("%d ", ptr->data);
        cout << ptr->data << " ";
        print_inorder(ptr->right);
    }
}

int main(){
	BST b1,b2;
	b1.insert_node(50);
	b1.insert_node(40);
	b1.insert_node(90);
	b1.insert_node(100);
	b1.insert_node(30);
	b1.print();
	
	b2.insert_node(55);
	b2.insert_node(44);
	b2.insert_node(22);
	b2.insert_node(88);
	b2.insert_node(66);
	b2.print();
	
	return 0;
}
