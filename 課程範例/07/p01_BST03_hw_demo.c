#include<stdio.h>
#include<stdlib.h>

struct BTreeNode
{
    char name[128];
    char phone[128];
    struct BTreeNode *left;
    struct BTreeNode *right;
};
typedef struct BTreeNode node;

void print_inorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_inorder(ptr->left);
        //printf("%d ", ptr->data);
        printf("%s\n", ptr->name);
        printf("%s\n\n", ptr->phone);
        print_inorder(ptr->right);
    }
}
node *insert_node(node *root, node input)
{
    node *new_node;
    node *current;
    node *parent;

    new_node = (node *)malloc(sizeof(node));
    //new_node->data = value;
    *new_node = input;
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
            //if(current->data > value)
            if(strcmp(current->name, input.name)>0)
                current = current->left;
            else
                current = current->right;
        }
        //if(parent->data > value)
        if(strcmp(parent->name, input.name)>0)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return root;
}

int main()
{
    node *root=NULL, *ptr;
    node input;
    int value;
    char op;
    
    while(1){

    	puts("i insert");
    	puts("l list inorder");
    	puts("m list preorder");
    	puts("n list postorder");
    	puts("q quit");

    	scanf(" %c",&op);
    	switch(op){
    		case 'i':
    			scanf("%s",input.name);
    			scanf("%s",input.phone);
    			root = insert_node(root, input);
    			break;
    		case 'l':
    			print_inorder(root);
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
