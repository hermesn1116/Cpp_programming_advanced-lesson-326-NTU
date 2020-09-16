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
	ptr = head;
	
	for(i = 0; i < 5; i++)
	{
		if(i != 4)
		{
			scanf("%d", &value);
			ptr->data = value;
			ptr->next = (node*)malloc(sizeof(node));
			ptr = ptr->next;
		}
		else
		{
			scanf("%d", &value);
			ptr->data = value;
			ptr->next = NULL;
		}
	}
	
	ptr = head;
	while(ptr != NULL)
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
