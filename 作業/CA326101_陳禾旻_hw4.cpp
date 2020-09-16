#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class node
{
	public :
		string Name;
		int Phone;
		string Email;
 		node *next;
		
	private :		
		friend class LinkedList;
};

class LinkedList
{
	public :	
		LinkedList();	
		void insert(node input);
		void remove(string value);
		void find(string value);
		int length();
		void print();
		
	private :		
		node *getnode();
		void freenode(node *p) ;
		void insert_node(node *ptr, node input);
		void delete_node(node *ptr);
		node *find_node(string value);		

		node *head;
};


int main()
{
	LinkedList List;
	node input, res;
	char Key;
	string name;
	int length;
	
	do 
	{
		cin >> Key;
		switch(Key)
		{
			case 'i' :
				cin >> input.Name >> input.Email >> input.Phone;
				List.insert(input);
				
				break;
			case 'd' :
				cin >> name;
				List.remove(name);
				
				break;
			case 'f' :
				cin >> name;
				List.find(name);
				
				break;
			case 'g' :
				length = List.length();
				cout << length << endl;
				
				break;
			case 'l' :
				List.print();
				
				break;
		}
	} while(Key != 'q');
	
	return 0;
}

LinkedList::LinkedList()
{
	head = NULL;
};

node *LinkedList::getnode() 
{
	node *nodeN;
	
	nodeN = new node;	
	if(nodeN == NULL)
	{
		cout << "°O¾ÐÅé¤£¨¬" << endl;
		exit(1);
	}
	
	return nodeN;
};

void LinkedList::freenode(node *p)
{
	delete p;
};

void LinkedList::insert_node(node *ptr, node input)
{ 
	node *new_node;  
	        
	new_node = getnode();   
	*new_node = input; 
	new_node->next = NULL;
	
	if(ptr == NULL) 
	{
		new_node->next = head; 
		head = new_node;
	}
	else
	{
		if(ptr->next == NULL) 
		{
			ptr->next = new_node;
		}
		else
		{
			new_node->next = ptr->next; 
			ptr->next = new_node;
		}
	}
};

void LinkedList::delete_node(node *ptr)
{
	node *previous; 
	
	if(ptr == head) 
	{
		head = head->next;
	}
	else
	{
		previous = head;
		while(previous->next != ptr) 
		{
			previous = previous->next;
		}			
		if(ptr->next == NULL) 
		{
			previous->next = NULL; 
		}
		else
		{
			previous->next = ptr->next;
		}
	}
	freenode(ptr); 
};

node *LinkedList::find_node(string value)
{
	node *ptr;
	
	ptr = head; 
	while(ptr != NULL)
	{ 
		if(ptr->Name == value) 
		{
			return ptr;
		}		
		ptr = ptr->next;
	} 
	
	return ptr;
};

int LinkedList::length() 
{
	int len = 0;
	node *q;
	
	q = head;
	while(q != NULL) 
	{
		len ++;
		q = q->next; 
	}
	
	return len;
};

void LinkedList::insert(node input)
{
	node *ptr;
	
	ptr = head;
	if(head == NULL)
	{
		insert_node(NULL, input);
	}
	else
	{
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}			
		insert_node(ptr, input);
	}
};

void LinkedList::remove(string value)
{
	node *ptr;
	
	ptr = find_node(value);
	if(ptr != NULL)
	{
		cout << "Delete ok" << endl
			 << ptr->Name << endl
			 << ptr->Email << endl
			 << setfill('0') << setw(10) << ptr->Phone << endl << endl;;
		delete_node(ptr);		
	}
	else
	{
		cout << "Can not delete" << endl;
	}
};

void LinkedList::find(string value)
{
	node *ptr;
	
	ptr = find_node(value);
	if(ptr != NULL)
	{
		cout << "found" << endl
			 << ptr->Name << endl
			 << ptr->Email << endl
			 << setfill('0') << setw(10) << ptr->Phone << endl << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
};

void LinkedList::print()
{
	node *q = head;
	
	while(q != NULL) 
	{
		cout << q->Name << endl
			 << q->Email << endl
			 << setfill('0') << setw(10) << q->Phone << endl << endl;			 
		q = q->next; 
	}
};
