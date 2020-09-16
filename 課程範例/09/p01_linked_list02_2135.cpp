#include<iostream>
#include<cstdlib>

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
	bool find(int num);
	bool remove(int num);	
private:
	
	node *find_node(int num);
	void delete_node( node *ptr);
	
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
	int N,K,M;
	linkedList *st;
	
	cin >> N;
	st = new linkedList[N];
	
	//input
	for(int i=0;i<N;i++){
		int value;
		cin >> value;
		while (value!=-1){
			st[i].insert(value);
			cin >> value;
		}			
	}
	
	//print all lists
	for(int i=0;i<N;i++)
		st[i].printList();
	
	cin >> K;
	cout << "Delete " << K << endl;
	for(int i=0;i<N;i++){
		st[i].remove(K);
		st[i].printList();
	}
		
	cin >> M;
	cout << "Find " << M << endl;
	for(int i=0;i<N;i++){
		if(st[i].find(M))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	
	return 0;
}
