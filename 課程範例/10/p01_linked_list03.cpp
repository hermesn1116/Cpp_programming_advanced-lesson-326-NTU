#include<iostream>

using namespace std;

template<class T>
class node{
template<class T2>friend class linkedList;
private:
	T data;
	node<T> *next;	
};


template<class T>
class linkedList{
public:
	linkedList();
	~linkedList();	
	void insert(T value);
	void printList();
	void releaseList();	
	bool find(T num);
	bool remove(T num);	
private:
	
	node<T> *find_node(T num);
	void delete_node( node<T> *ptr);
	
	node<T> *getnode () ;	
	void freenode (node<T> *p);	
	void insert_node ( node<T> *ptr, node<T> input);
	
	node<T> *head;
	node<T> *tail;
};

template<class T>
linkedList<T>::linkedList(){
	head = NULL;
	tail = NULL;
}

template<class T>
linkedList<T>::~linkedList(){
	releaseList();
}

template<class T>
void linkedList<T>::insert(T value){
	node<T> input;
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

template<class T>
void linkedList<T>::printList(){
    node<T> *ptr = head;
    while(ptr!=NULL){
        //printf("%d ", ptr->data);
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    //puts("");
    cout << endl;
}

template<class T>
void linkedList<T>::releaseList(){
    //release
    node<T> *ptr = head;
    node<T> *p4d;
    
    while(ptr!=NULL){
        p4d = ptr->next;
        delete ptr;//free(ptr);
        ptr = p4d;
    }
}

template<class T>
node<T> *linkedList<T>::getnode () 
{
    node<T> *p;
    //p = (node *) malloc(sizeof(node));
    p = new node<T>;
    if ( p == NULL)
    {
        cout << "out of mem\n";//printf ("?????");
        exit(1);
    }
    return p;
}

template<class T>
void linkedList<T>::freenode (node<T> *p)
{
    delete p;//free(p);
}

template<class T>
void linkedList<T>::insert_node ( node<T> *ptr, node<T> input)
{ 
    node<T> *new_node;
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

template<class T>
node<T> *linkedList<T>::find_node( T num)
{
    node<T> *ptr;
    ptr = head; /* ?????? */
    while ( ptr != NULL ) /* ???? */
    { 
        if ( ptr->data == num ) /* ??data */
                  return ptr; /* ?? (ptr != NULL)*/
        ptr = ptr->next; /* ?????? */
    } 
    return ptr; /* ??? (ptr == NULL)*/
}

template<class T>
void linkedList<T>::delete_node(node<T> *ptr)
{
    node<T> *pre;
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

template<class T>
bool linkedList<T>::find(T num){
	node<T> *ptr = find_node(num);
	if(ptr==NULL)
		return false;
	else
		return true;
}

template<class T>
bool linkedList<T>::remove(T num){
	node<T> *ptr = find_node(num);
	if(ptr==NULL)
		return false;
	else{
		delete_node(ptr);
		return true;
	}		
}

int main(){
	
	linkedList<int> st1;
	linkedList<string> st2;
	
	st1.insert(10);
	st1.insert(20);
	st1.insert(30);
	st1.insert(40);
	st1.insert(50);
	st1.printList();
	st1.remove(30);
	st1.remove(99);
	st1.printList();
	
	st2.insert("apple");
	st2.insert("banana");
	st2.insert("pineapple");
	st2.printList();
	
	if(st2.find("apple")){
		cout << "found apple\n";
	}
	if(st2.find("QQQ"))
		cout << "found QQQ\n";
	else
		cout << "QQQ not found\n";
		
	st2.remove("banana");
	st2.printList();
	
	return 0;
}
