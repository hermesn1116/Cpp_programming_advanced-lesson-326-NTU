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

node *search_node(node *ptr, int value)
{
    node *temp;
    
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
}


node *insert_node(node *root, int value)
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
    return root;
}

int main()
{
    node *root=NULL, *ptr;
    int value;
    char op;
    
    while(1){
    	/*
    	puts("i insert");
    	puts("l list inorder");
    	puts("m list preorder");
    	puts("n list postorder");
    	puts("q quit");
    	*/
    	scanf(" %c",&op);
    	switch(op){
    		case 'i':
    			scanf("%d",&value);
    			root = insert_node(root, value);
    			break;
    		case 'l':
    			print_inorder(root);
    			puts("");
    			break;
    		case 'm':
    			print_preorder(root);
    			puts("");
    			break;
    		case 'n':
    			print_postorder(root);
    			puts("");
    			break;
    		case 'q':
    			return 0;
    			break;
		}
		system("pause");
		system("cls");
	}
    
  

}
