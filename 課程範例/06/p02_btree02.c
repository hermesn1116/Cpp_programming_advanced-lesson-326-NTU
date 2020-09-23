#include<stdio.h>
#include<stdlib.h>

struct BTreeNode
{
    int data;
    struct BTreeNode *left;
    struct BTreeNode *right;
};
typedef struct BTreeNode node;

void print_inorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_inorder(ptr->left);
        printf("%d ", ptr->data);
        print_inorder(ptr->right);
    }
}
void print_preorder(node *ptr)
{
    if(ptr != NULL)
    {
        printf("%d ", ptr->data);
        print_preorder(ptr->left);
        print_preorder(ptr->right);
    }
}
void print_postorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_postorder(ptr->left);
        print_postorder(ptr->right);        
        printf("%d ", ptr->data);
    }
}

int main()
{
    node *root;
    
    //Level 1
	root = (node *)malloc(sizeof(node));
	root->data = 5;
	 
	//Level 2
	root->left = (node *)malloc(sizeof(node));
	root->left->data = 4;
	root->left->left = NULL;
	root->left->right = NULL;
	 
	root->right = (node *)malloc(sizeof(node));
	root->right->data = 6;
	root->right->left = NULL;
	root->right->right = NULL;
	 
	//Level 3
	root->left->left = (node *)malloc(sizeof(node));
	root->left->left->data = 2;
	root->left->left->left = NULL;
	root->left->left->right = NULL;
	 
	root->right->right = (node *)malloc(sizeof(node));
	root->right->right->data = 8;
	root->right->right->left = NULL;
	root->right->right->right = NULL;
	 
	//Level 4
	root->left->left->left= (node *)malloc(sizeof(node));
	root->left->left->left->data = 1;
	root->left->left->left->left = NULL;
	root->left->left->left->right = NULL;
	 
	root->left->left->right= (node *)malloc(sizeof(node));
	root->left->left->right->data = 3;
	root->left->left->right->left = NULL;
	root->left->left->right->right = NULL;
	 
	root->right->right->left = (node *)malloc(sizeof(node));
	root->right->right->left->data = 7;
	root->right->right->left->left = NULL;
	root->right->right->left->right = NULL;
	 
	root->right->right->right = (node *)malloc(sizeof(node));
	root->right->right->right->data = 9;
	root->right->right->right->left = NULL;
	root->right->right->right->right = NULL;
    
    print_preorder(root);
    puts("");
    print_inorder(root);
    puts("");
    print_postorder(root);
    puts("");
}
