#include <iostream>
#include <string>

using namespace std;

class node
{
	public :
		string Name;
		string Phone;
		string Email;
 		node *left;
 		node *right;
		
	private :		
		friend class binarytree;
};

class binarytree
{
	public :	
		binarytree();	
		void insert(node input);
		void remove(string value);
		void find(string value);
		int length();
		void print_inorder();
		void print_preorder();
		void print_postorder();
		
	private :		
		node *getnode();
		void freenode(node *p) ;
		void insert_node(node *ptr, node input);
		node *find_parent(binarytree *ptr, int value, int *pos);
		void delete_node(node *ptr);
		node *find_node(string value);		

		node *root;
};


int main(void)
{
	
	
	return 0;
}

binarytree::binarytree()
{
	root = NULL; 
};	
	
void binarytree::insert(node input)
{
	
};

void binarytree::remove(string value)
{
	
};

void binarytree::find(string value)
{
	
};

void binarytree::print_inorder()
{
	node *tmp = root, *tmpL, *tmpR;
	
	if(tmp != NULL)
    {
        tmp->left;
        printf("%d ", ptr->data);
        print_inorder(ptr->right);
    }
};

void binarytree::print_preorder()
{
	
};

void binarytree::print_postorder()
{
	
};
		
node *binarytree::getnode()
{
	node *nodeN;
	
	nodeN = new node;
	
	return nodeN;
};

void binarytree::freenode(node *p)
{
	delete p;
};

void binarytree::insert_node(node *ptr, node input)
{
	
};

node *binarytree::find_parent(binarytree *ptr, int value, int *pos)
{
	
};

void binarytree::delete_node(node *ptr)
{
	
};

node *find_node(string value)
{
	
};	
