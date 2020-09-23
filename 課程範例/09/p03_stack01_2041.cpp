#include<iostream>
#include<cstdlib>

using namespace std;

class node{
friend class linkedList;
friend class stack;
friend class queue;
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
	bool find(int num);
	bool remove(int num);	
//private:
protected:	
	node *find_node(int num);
	void delete_node( node *ptr);
	
	node *getnode () ;	
	void freenode (node *p);	
	void insert_node ( node *ptr, node input);
	
	node *head;
	node *tail;
};

class stack:protected linkedList{
public:
	stack(){
	}
	void push(int n){
		node value;
		value.data = n;
		insert_node(NULL,value);
	}
	int pop(){
		if(head == NULL)
			return -1;
		int value = head->data;
		delete_node(head);
		
		return value;
	}
private:	
};


class queue:protected linkedList{
public:
	queue(){
	}
	void enqueue(int n){
		node value;
		value.data = n;
		insert_node(tail,value);
	}
	int dequeue(){
		if(head == NULL)
			return -1;
		int value = head->data;
		delete_node(head);
		
		return value;
	}
private:	
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
        if(head==NULL)
        	tail = new_node;
        head = new_node;
    }
    else
    {
        if ( ptr->next == NULL ){
            ptr->next = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = ptr->next; 
            ptr->next = new_node;
        }
    }
    //return (head);
}


node *linkedList::find_node( int num)
{
    node *ptr;
    ptr = head; /* ?????? */
    while ( ptr != NULL ) /* ???? */
    { 
        if ( ptr->data == num ) /* ??data */
                  return ptr; /* ?? (ptr != NULL)*/
        ptr = ptr->next; /* ?????? */
    } 
    return ptr; /* ??? (ptr == NULL)*/
}


void linkedList::delete_node(node *ptr)
{
    node *pre;
    if ( ptr == head ) 
    {
        head = head->next;
    }
    else
    {
        pre = head;
        
        //printf(" pre => %d (%d)\n", pre, pre->data);
        //printf(" pre next => %d (%d)\n", pre->next, pre->next->data);
        while ( pre->next != ptr ){
            pre = pre->next;    
            //printf(" pre => %d (%d)\n", pre, pre->data);
            //printf(" pre next => %d (%d)\n", pre->next, pre->next->data);
        }
        if ( ptr->next == NULL )
            pre->next = NULL;
        else
            pre->next = ptr->next;
    }
    freenode(ptr);
    //return(head);
}

bool linkedList::find(int num){
	node *ptr = find_node(num);
	if(ptr==NULL)
		return false;
	else
		return true;
}
bool linkedList::remove(int num){
	node *ptr = find_node(num);
	if(ptr==NULL)
		return false;
	else{
		delete_node(ptr);
		return true;
	}	
	
}

int main(){
	int N,M;
	
	cin >> N >> M;
	
	
	stack *s = new stack[N];
	queue *q = new queue[N];
	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			int value;
			cin >> value;
			s[j].push(value);
			q[j].enqueue(value);
		}
	}
	
	cout << "Stack Output:\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout << s[i].pop() << " ";
		}
		cout << endl;
	}
	
	cout << "Queue Output:\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout << q[i].dequeue() << " ";
		}
		cout << endl;
	}
	
	return 0;
}
