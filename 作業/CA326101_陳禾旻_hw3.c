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
		
	for(i = 0; i < 5; i++)
	{
		scanf("%d", &value);
		ptr = (node*)malloc(sizeof(node));
		ptr->data = value;
		ptr->next = head;
		head = ptr;
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
