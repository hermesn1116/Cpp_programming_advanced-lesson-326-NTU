#include <stdio.h>
#include <stdlib.h> 

struct _node
{
	int data;
	struct _node *next;
};
typedef struct _node node;

node *getnode();
node *insertNode(node *head, node *ptr, node input);
node *findNode(node *head, int target);
node *deleteNode(node *head, node *target);
void printList(node *head);
void releaseList(node *head);

int main(void)
{
	node *head = NULL, *tmp, *res, input;
	char opt;
	int val;
	
	do
	{
		scanf(" %c", &opt);
		switch(opt)
		{
			case 'i' :
				scanf("%d", &input.data);
				if(head == NULL)
				{
					head = insertNode(head, NULL, input);
					tmp = head;
				}
				else
				{
					head = insertNode(head, tmp, input);
					tmp = tmp->next;
				}
				
				break;
			case 'd' :
				scanf("%d", &val);
				res = findNode(head, val);
				if(res != NULL)
				{
					head = deleteNode(head, res);
					printf("Delete ok\n");
				}
				else
				{
					printf("Can not delete\n");
				}
				
				break;
			case 'f' :
				scanf("%d", &val);
				res = findNode(head, val);
				if(res != NULL)
				{
					printf("found %d\n", val);
				}
				else
				{
					printf("Not found\n");
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

node *getnode()
{
	node *newNode;
	
	newNode = (node*)malloc(sizeof(node));
	if(newNode == NULL)
	{
		printf("out of memory\n");
		exit(1);
	}
	
	return newNode;
};

node *insertNode(node *head, node *ptr, node input)
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

	return head;
};

node *findNode(node *head, int target)
{
	node *tmp = head;
	
	while(tmp != NULL)
	{
		if(tmp->data == target)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	
	return NULL;
};

node *deleteNode(node *head, node *target)
{
	node *previous; 
	
	if(target == head) 
	{
		head = head->next;
	}
	else
	{
		previous = head;
		while(previous->next != target)
		{
			previous = previous->next;
		}			
		if (target->next == NULL)
		{
			previous->next = NULL;
		}			
		else
		{
			previous->next = target->next;
		}
	}
	
	free(target);
	
	return head;
};

void printList(node *head)
{
	node *tmp;
	
	tmp = head;
	while(tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
};

void releaseList(node *head)
{
	node *tmp;	
	
	while(head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}	
};
