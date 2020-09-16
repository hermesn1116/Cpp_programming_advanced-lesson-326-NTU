#include <stdio.h>
#include <stdlib.h> 

struct _node
{
	int data;
	struct _node *next;
};
typedef struct _node node;

int main(void)
{
	node *head, *ptr;
	int value, i;
	
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
		
	while(1) 
	{
		scanf("%d", &value);
		if(value != -1)
		{
			ptr = (node*)malloc(sizeof(node));
			ptr->data = value;
			ptr->next = head;
			head = ptr;
		}
		else
		{
			break;
		}
	} 
	
	ptr = head;
	while(ptr->next != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	} 
	
	ptr = head->next;
	free(head);
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		free(ptr);
	}
	
	return 0;
}
