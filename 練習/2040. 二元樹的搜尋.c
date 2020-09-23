#include <stdio.h>
#include <stdlib.h> 

struct _binarytree
{
	int data;
	struct _binarytree *left;
	struct _binarytree *right;
}; typedef struct _binarytree binarytree;

binarytree *search_node(binarytree *ptr, int value);

int main(void)
{
	binarytree *root, *res;
	int target;
	
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
	
	scanf("%d", &target);
	
	res = search_node(root, target);
	if(res != NULL)
	{
		printf("\nfound %d\n", res->data);
	}
	else
	{
		printf("\nnot found");
	}
	
	return 0;
}

binarytree *search_node(binarytree *ptr, int value)
{
    binarytree *temp;
 
    if(ptr != NULL)
    {
    	printf("%d ", ptr->data);
        if(ptr->data == value)
            return ptr;
        else
        {        	
            temp = search_node(ptr->left, value);
            if(temp != NULL)
                return temp;
            temp = search_node(ptr->right, value);
            if(temp != NULL)
                return temp;
        }
    }
    return NULL;
};
