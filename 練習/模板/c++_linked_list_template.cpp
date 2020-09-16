#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;


template <class T>
class node
{
	public:
		T data;
 		node<T> *next;
};

template <class T>
class LinkedList
{
	public:
		LinkedList();
		void insert(T &value);
		void remove(T &value);
		void find(T &value);
		void print();
	private:
		node<T> *getnode ();
		void freenode (node<T> *p) ;
		void insert_node (node<T> *ptr, T &value);
		void delete_node(node<T> *ptr);
		node<T> *find_node(T &num);
		int length ();

		node<T> *head;
		node<T> *tail;
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
}

template <class T>
node<T> *LinkedList<T>::getnode () /* ����Ʋ��ͤ@�ӷs�`�I */
{
	node<T> *p;
	p = new node<T>;
	if ( p == NULL)
	{
		cout << "�O���餣��" << endl;
		exit(1);
	}
	return(p);
}

template <class T>
void LinkedList<T>::freenode (node<T> *p) /* ����ƱN�`�I�ٵ��O���� */
{
	delete p;
}

template <class T>
void LinkedList<T>::insert_node ( node<T> *ptr, T &value)
{ 
	node<T> *new_node;            /* �s�`�I�����ܼ� */
	new_node = getnode();    /* �إ߷s�`�I,���o�@�ӥi�θ`�I */
	new_node->data = value; /* �إ߸`�I���e */
	new_node->next = NULL; /* �]�w���Ъ�� */
	
	if ( ptr == NULL ) /* ����ptr�O�_�ONULL */
	{
		/* �Ĥ@�ر��p: ���J�Ĥ@�Ӹ`�I */
		new_node->next = head; /* �s�`�I������C�}�l */
		head = new_node;
	}
	else
	{
		if ( ptr->next == NULL ) /* �O�_�O��C���� */
			/* �ĤG�ر��p: ���J�̫�@�Ӹ`�I */
			ptr->next = new_node; /* �̫���V�s�`�I */
		else
		{
			/* �ĤT�ر��p: ���J���������`�I */
			new_node->next = ptr->next; /* (3) �s�`�I���V�U�@�`�I (3)*/
			ptr->next = new_node; /* �`�Iptr���V�s�`�I (4)*/
		}
	}
}

template <class T>
void LinkedList<T>::delete_node(node<T> *ptr)
{
	node<T> *previous; /* ���V�e�@�`�I */
	if ( ptr == head ) /* �O�_�O��C�}�l */
	/* �Ĥ@�ر��p: �R���Ĥ@�Ӹ`�I */
	{
		head = head->next;
	}
	else
	{
		previous = head;
		while ( previous->next != ptr ) /* ��`�Iptr���e�`�I */
			previous = previous->next;
		if ( ptr->next == NULL ) /* �O�_�O��C���� */
		/* �ĤG�ر��p: �R���̫�@�Ӹ`�I */
			previous->next = NULL; /* �̫�@�Ӹ`�I */
		else
		/* �ĤT�ر��p: �R�������`�I */
			previous->next = ptr->next; /* ��(3)���B�J(1) */
	}
	freenode(ptr); /* ����ƱN�`�I�k�ٵ��O���� */
}
template <class T>
node<T> *LinkedList<T>::find_node(T &num)
{
	node<T> *ptr;
	ptr = head; /* ���V��C�_�l */
	while ( ptr != NULL ) /* ���X��C */
	{ 
		if ( ptr->data == num ) /* ��Mdata */
		return (ptr);
		ptr = ptr->next; /* ���V�U�@�`�I */
	} 
	return (ptr);
}
template <class T>
int LinkedList<T>::length () /* ����ƭp��`�I���쵲���� */
{
	int num=0;
	node<T> *q = head;
	while (q != NULL) 
	{
		num ++;
		q = q->next; 
	}
	return(num);
}

template <class T>
void LinkedList<T>::insert(T &value)
{
	if(head==NULL)
	{
		head = getnode();
		head->data=value;
		head->next=NULL;
		tail = head;
	}
	else
	{
		insert_node(tail, value);
		tail = tail->next;
	}
	cout << "��ƴ��J���\!" <<  endl;
}

template <class T>
void LinkedList<T>::remove(T &value)
{
	node<T> *prev, *ptr;
	ptr = find_node(value);
	if(ptr != NULL)
	{
		if(length()==1)
		{
			delete_node(ptr);
			tail = NULL;
		}
		else if(ptr->next==NULL)
		{
			prev = head;
			while(prev->next != ptr)
				prev = prev->next;
			delete_node(ptr);
			tail = prev;
		}
		else
		{
			delete_node(ptr);
		}
		cout << "��Ƥw�R��!" <<  endl;
	}
	else
	{
		cout << "�L�����!" <<  endl;
	}
}

template <class T>
void LinkedList<T>::find(T &value)
{
	node<T> *ptr;
	ptr = find_node(value);
	if(ptr != NULL)
	{
		cout << "���`�I���: " <<  ptr->data << endl;
	}
	else
	{
		cout << "�䤣��Ӹ`�I���" << endl;
	}
}

template <class T>
void LinkedList<T>::print()
{
	node<T> *q = head;
	while (q != NULL) 
	{
		cout << q->data << " ";
		q = q->next; 
	}
	cout << endl;
}

int main()
{	
	LinkedList<int> list;
	int value;
	char key;
	while(1)
	{
		cout << "i: ���J" << endl;
		cout << "d: �R��" << endl;
		cout << "f: �M��" << endl;
		cout << "l: �C�L" << endl;
		cout << "e: ���}" << endl;
		cout << "> ";
		key = getche();
		cout << endl;
		switch(key)
		{
			case 'i':
				cout << "��J���J��Ƥ��e: ";
				cin >> value;
				list.insert(value);
				break;
			case 'd':
				cout << "��J�R����Ƥ��e: ";
				cin >> value;
				list.remove(value);
				break;
			case 'f':
				cout << "��J�M���Ƥ��e: ";
				cin >> value;
				list.find(value);
				break;
			case 'l':
				list.print();
				break;
			case 'e':
				cout << "ByeBye!" << endl; 
				exit(0);
			default:
				cout << "��J�ȿ��~!" << endl; 
		}
		cout << endl; 
	}
	return 0;
}