#include<stdlib.h>
#include<stdio.h>

struct _node{     
    //???? ????;
    int data;
    struct _node *next;
};  
typedef struct _node node;

int main()
{
    node *head, *ptr;
    head = (node *)malloc(sizeof(node));
    ptr = head;
    int n = 5,i;
    //printf("head => %d\n", head);
    //printf("ptr => %d\n", ptr);
    int value;

	for(i=0;i<n;i++){
		if(i!=n-1){		
		    scanf("%d", &value);
		    ptr->data = value;
		    ptr->next = (node *)malloc(sizeof(node));
		    ptr = ptr->next;    
		    //printf("ptr => %d\n", ptr);
	    }
	    else{
		    scanf("%d", &value);
		    ptr->data = value;
		    ptr->next = NULL;	
		}	    
	}
	
    ptr = head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
  
  return 0;
}
