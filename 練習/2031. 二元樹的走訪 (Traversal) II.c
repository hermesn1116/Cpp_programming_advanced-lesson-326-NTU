#include <stdio.h>
#include <stdlib.h> 

struct _binarytree
{
	int data;
	struct _binarytree *left;
	struct _binarytree *right;
}; typedef struct _binarytree binarytree;

void print_inorder(binarytree *ptr);
void print_preorder(binarytree *ptr);
void print_postorder(binarytree *ptr);


int main(void)
{
	binarytree *root;
	
	root = (binarytree *)malloc(sizeof(binarytree));
	root->data = 5;
 

	root->left = (binarytree *)malloc(sizeof(binarytree));
	root->left->data = 4;
	root->left->left = NULL;
	root->left->right = NULL;
 
	root->right = (binarytree *)malloc(sizeof(binarytree));
	root->right->data = 6;
	root->right->left = NULL;
	root->right->right = NULL;
	
	root->left->left = (binarytree *)malloc(sizeof(binarytree));
	root->left->left->data = 2;
	root->left->left->left = NULL;
	root->left->left->right = NULL;
	 
	root->right->right = (binarytree *)malloc(sizeof(binarytree));
	root->right->right->data = 8;	
	root->right->right->left = NULL;
	root->right->right->right = NULL;
	
	root->left->left->left= (binarytree *)malloc(sizeof(binarytree));
	root->left->left->left->data = 1;
	root->left->left->left->left = NULL;
	root->left->left->left->right = NULL;
	 
	root->left->left->right= (binarytree *)malloc(sizeof(binarytree));
	root->left->left->right->data = 3;
	root->left->left->right->left = NULL;
	root->left->left->right->right = NULL;
 
	root->right->right->left = (binarytree *)malloc(sizeof(binarytree));
	root->right->right->left->data = 7;
	root->right->right->left->left = NULL;
	root->right->right->left->right = NULL;
 
	root->right->right->right = (binarytree *)malloc(sizeof(binarytree));
	root->right->right->right->data = 9;
	root->right->right->right->left = NULL;
	root->right->right->right->right = NULL;
	
	print_preorder(root);
	printf("\n");
	print_inorder(root);
	printf("\n");
	print_postorder(root);
	printf("\n");
	
	return 0;
}

void print_inorder(binarytree *ptr)
{
	if(ptr != NULL)
    {
        print_inorder(ptr->left);
        printf("%d ", ptr->data);
        print_inorder(ptr->right);
    }
};

void print_preorder(binarytree *ptr)
{
	if(ptr != NULL)
    {
    	printf("%d ", ptr->data);
        print_preorder(ptr->left);
        print_preorder(ptr->right);
    }
};

void print_postorder(binarytree *ptr)
{
	if(ptr != NULL)
    {
        print_postorder(ptr->left);        
        print_postorder(ptr->right);
		printf("%d ", ptr->data);
    }
};
