#include<stdio.h>
#include<stdlib.h>

struct _node{     
    //???? ????;
    int data;
    struct _node *next;
};  
typedef struct _node node;

int main()
{
    node *head=NULL, *ptr;
    int value;

    while(1){
        scanf("%d", &value);

        
        if(value == -1)
            break;
        if(head==NULL){
            head = (node *)malloc(sizeof(node));
            //printf("head => %d\n", head);
            ptr = head;
            ptr->data = value;
            ptr->next = NULL;
        }
        else{
            ptr->next = (node *)malloc(sizeof(node));
            ptr = ptr->next;        
            //printf("ptr => %d\n", ptr);    
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
