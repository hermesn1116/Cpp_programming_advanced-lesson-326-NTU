#include <stdio.h>
#include <stdlib.h> 

struct _node
{
	int data;
	struct node *next;
};
typedef struct _node node;

int main(void)
{
	node *head, *ptr;
	int value, i;
	
	head = (node*)malloc(sizeof(node));
	ptr = head;
	
	while(1)
	{
		scanf("%d", &value);
		if(value != -1)
		{
			ptr->data = value;
			ptr->next = (node*)malloc(sizeof(node));
			ptr = ptr->next;
		}
		else
		{
			ptr->data = NULL;
			ptr->next = NULL;
			break;
		}
	}
	
	ptr = head;
	while(ptr->data != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	} 
	
	return 0;
}
