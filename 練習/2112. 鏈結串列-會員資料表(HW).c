#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct _node
{
	char Name[128];
	int Phone;
	char Email[128];
	struct _node *next;
};
typedef struct _node node;

node *getnode();
node *insertNode(node *head, node *ptr, node input);
node *findNode(node *head, char target[128]);
node *deleteNode(node *head, node *target);
void printList(node *head);
void releaseList(node *head);

int main(void)
{
	node *head = NULL, *tmp, *res, input;
	char opt;
	char val[128];
	
	do
	{
		scanf(" %c", &opt);
		switch(opt)
		{
			case 'i' :
				scanf("%s %d %s", input.Name, &input.Phone, input.Email);
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
				scanf("%s", val);
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
				scanf("%s", val);
				res = findNode(head, val);
				if(res != NULL)
				{
					printf("found\n");
					printf("%s\n%s\n%010d\n", res->Name, res->Email, res->Phone);
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
	node *newNode;
	
	newNode = getnode();
	*newNode = input;
	newNode->next = NULL;
	    
	if(ptr == NULL)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		if(ptr->next == NULL)
		{
			ptr->next = newNode;
		}	            
		else
		{
			newNode->next = ptr->next; 
			ptr->next = newNode;
		}
	}

	return head;
};

node *findNode(node *head, char target[128])
{
	node *tmp = head;
	
	while(tmp != NULL)
	{
		if(strcmp(tmp->Name, target) == 0)
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
		printf("%s\n%s\n%010d\n\n", tmp->Name, tmp->Email, tmp->Phone);
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
