#include <stdio.h>
#include <stdlib.h> 

struct _binarytree
{
	int data;
	struct _binarytree *left;
	struct _binarytree *right;
}; typedef struct _binarytree binarytree;

binarytree *insert_binarytree(binarytree *root, int value);
void print_inorder(binarytree *ptr);
void print_preorder(binarytree *ptr);
void print_postorder(binarytree *ptr);


int main(void)
{
	binarytree *root;
	char opt;
	int val;
	
	root = NULL;
	
	do
	{
		scanf(" %c", &opt);
		switch(opt)
		{
			case 'i' :
				scanf("%d", &val);
				root = insert_binarytree(root, val);
				
				break;
			case 'l' :
				print_inorder(root);
				printf("\n");
				
				break;
			case 'm' :
				print_preorder(root);
				printf("\n");
				
				break;
			case 'n' :
				print_postorder(root);
				printf("\n");
				
				break;
		}
	} while(opt != 'q');	
	
	return 0;
}

binarytree *insert_binarytree(binarytree *root, int value)
{
	binarytree *new_node, *current, *parent;
	
	new_node = (binarytree*)malloc(sizeof(binarytree));
	new_node->data = value;
	new_node->left = NULL;
	new_node->right = NULL;
	
	if(root == NULL)
	{
		root = new_node;
	}
	else
	{
		current = root;
		while(current != NULL)
		{
			parent = current;
			if(current->data > value)
			{
				current = current->left;
			}				
			else
			{
				current = current->right;
			}				
		}
		if(parent->data > value)
		{
			parent->left = new_node;
		}			
		else
		{
			parent->right = new_node;
		}
	}
	
	return root;
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
