#include<stdio.h>
#include<stdlib.h>

struct _node{     
    int data;
    struct _node *next;
};  
typedef struct _node node;

void printList(node *ptr){
    //ptr = head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    puts("");
}
void releaseList(node *ptr){
    //release
    //ptr = head;
    node *p4d;
    
    while(ptr!=NULL){
        p4d = ptr->next;
        free(ptr);
        ptr = p4d;
    }
}


node *getnode () 
{
    node *p;
    p = (node *) malloc(sizeof(node));
    if ( p == NULL)
    {
        printf ("?????");
        exit(1);
    }
    return p;
}

void freenode (node *p)
{
    free(p);
}

node *insert_node (node *head, node *ptr, node input)
{ 
    node *new_node;
    new_node = getnode();
    *new_node = input;
    new_node->next = NULL;
    
    if ( ptr == NULL )    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        if ( ptr->next == NULL )
            ptr->next = new_node;
        else
        {
            new_node->next = ptr->next; 
            ptr->next = new_node;
        }
    }
    return (head);
}


int main(){
	node *head=NULL, *ptr;
    node input;
    int value;
	char op;		
	
	while(1){
		/*
		puts("i insert");
		puts("l list");
		puts("q quit");
		*/
		scanf(" %c", &op);
		
		switch(op){
			case 'i':
				scanf("%d", &input.data);
				if(head==NULL){				
				    head = insert_node(head,NULL,input);
				    ptr = head;
			    }
			    else{				
				    head = insert_node(head,ptr,input);
				    ptr = ptr->next;
			    }
				break;
			case 'l':
				printList(head); 
				break;
			case 'q':
				return 0;
				break;
		}
		
		system("pause");
		system("cls");
	}
	releaseList(head);
	return 0;
}
