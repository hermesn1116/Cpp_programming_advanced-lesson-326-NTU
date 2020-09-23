#include<iostream>

using namespace std;

class node{
friend class linkedList;
private:
	int data;
	node *next;	
};

class linkedList{
public:
	linkedList();
	~linkedList();	
	void insert(int value);
	void printList();
	void releaseList();	
	
private:
	node *getnode () ;	
	void freenode (node *p);	
	void insert_node ( node *ptr, node input);
	
	node *head;
	node *tail;
};

linkedList::linkedList(){
	head = NULL;
	tail = NULL;
}
linkedList::~linkedList(){
	releaseList();
}

void linkedList::insert(int value){
	node input;
	input.data = value;
	if(head==NULL){
		insert_node ( NULL, input);
		tail = head;
	}
	else{
		insert_node ( tail, input);
		tail = tail->next;
	}
		
}
void linkedList::printList(){
    node *ptr = head;
    while(ptr!=NULL){
        //printf("%d ", ptr->data);
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    //puts("");
    cout << endl;
}
void linkedList::releaseList(){
    //release
    node *ptr = head;
    node *p4d;
    
    while(ptr!=NULL){
        p4d = ptr->next;
        delete ptr;//free(ptr);
        ptr = p4d;
    }
}

node *linkedList::getnode () 
{
    node *p;
    //p = (node *) malloc(sizeof(node));
    p = new node;
    if ( p == NULL)
    {
        cout << "out of mem\n";//printf ("?????");
        exit(1);
    }
    return p;
}

void linkedList::freenode (node *p)
{
    delete p;//free(p);
}

void linkedList::insert_node ( node *ptr, node input)
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
    //return (head);
}

int main(){
	
	linkedList st1, st2;
	st1.insert(10);
	st1.insert(20);
	st1.insert(30);
	st1.insert(40);
	st1.insert(50);
	st1.printList();
	
	st2.insert(33);
	st2.insert(44);
	st2.insert(55);
	st2.insert(66);

	st2.printList();
	
	return 0;
}
