#include <stdio.h>
#include <stdlib.h> 

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

void printList();	
void releaseList();
node *getnode();
void freenode();	
node *insert_node();	

int main(void)
{
	node *head = NULL, *pt, input;
	char opt;
	
	do
	{
		scanf(" %c", &opt);
		
		switch(opt)
		{
			case 'i' :
				scanf("%d", &input.data);
				if(head == NULL)
				{
					head = (node*)malloc(sizeof(node));
					head->data = input.data;
					head->next = NULL;
					pt = head;
				}
				else
				{
					head = insert_node(head, pt, input);
					pt = pt->next;
				}
				break;
			case 'l' :
				printList(head);
				printf("\n");
				break;
		}
	} while(opt != 'q');
	
	releaseList(head);
	
	return 0;
}

void printList(node *ptr)
{
	while(ptr != NULL)
	{
	    printf("%d ", ptr->data);
		ptr = ptr->next;
	}
};
	
void releaseList(node *ptr)
{
	node *p4d;
	
	while(ptr != NULL)
	{
		p4d = ptr->next;
		free(ptr);
		ptr = p4d;
	}
};

node *getnode() 
{
	node *p;
	
	p = (node *) malloc(sizeof(node));

	if ( p == NULL)
	{
		printf ("°O¾ÐÅé¤£¨¬");
		exit(1);
	}

	return p;
};

void freenode(node *p)
{
	free(p);
};
	
node *insert_node(node *head, node *ptr, node input)
{ 
	node *new_node;
	
	new_node = getnode();
	*new_node = input;
	new_node->next = NULL;
	    
	if (ptr == NULL)
	{
		new_node->next = head;
		head = new_node;
	}
	else
	{
		if (ptr->next == NULL)
		{
			ptr->next = new_node;
		}	            
		else
		{
			new_node->next = ptr->next; 
			ptr->next = new_node;
		}
	}

	return (head);	
};	
