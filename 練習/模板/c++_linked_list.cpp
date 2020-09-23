#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class node
{
	private:
		int data;
 		node *next;
		friend class LinkedList;
};
class LinkedList
{
	public:
		LinkedList();
		void insert(int value);
		void remove(int value);
		void find(int value);
		void print();
	private:
		node *getnode ();
		void freenode (node *p) ;
		void insert_node (node *ptr, int value);
		void delete_node(node *ptr);
		node *find_node(int num);
		int length ();

		node *head;
};

LinkedList::LinkedList()
{
	head = NULL;
}

node *LinkedList::getnode () /* ����Ʋ��ͤ@�ӷs�`�I */
{
	node *p;
	p = new node;
	if ( p == NULL)
	{
		cout << "�O���餣��" << endl;
		exit(1);
	}
	return(p);
}
void LinkedList::freenode (node *p) /* ����ƱN�`�I�ٵ��O���� */
{
	delete p;
}

void LinkedList::insert_node ( node *ptr, int value)
{ 
	node *new_node;            /* �s�`�I�����ܼ� */
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

void LinkedList::delete_node(node *ptr)
{
	node *previous; /* ���V�e�@�`�I */
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
node *LinkedList::find_node(int num)
{
	node *ptr;
	ptr = head; /* ���V��C�_�l */
	while ( ptr != NULL ) /* ���X��C */
	{ 
		if ( ptr->data == num ) /* ��Mdata */
		return (ptr);
		ptr = ptr->next; /* ���V�U�@�`�I */
	} 
	return (ptr);
}
int LinkedList::length () /* ����ƭp��`�I���쵲���� */
{
	int num=0;
	node *q = head;
	while (q != NULL) 
	{
		num ++;
		q = q->next; 
	}
	return(num);
}

void LinkedList::insert(int value)
{
	node *ptr;
	
	ptr = head;
	if(head==NULL)
	{
		insert_node(NULL, value);
	}
	else
	{
		while(ptr->next != NULL)
			ptr = ptr->next;
		insert_node(ptr, value);
	}
	cout << "��ƴ��J���\!" <<  endl;
}

void LinkedList::remove(int value)
{
	node *ptr;
	ptr = find_node(value);
	if(ptr != NULL)
	{
		delete_node(ptr);
		cout << "��Ƥw�R��!" <<  endl;
	}
	else
	{
		cout << "�L�����!" <<  endl;
	}
}

void LinkedList::find(int value)
{
	node *ptr;
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

void LinkedList::print()
{
	node *q = head;
	while (q != NULL) 
	{
		cout << q->data << " ";
		q = q->next; 
	}
	cout << endl;
}

int main()
{
	LinkedList list;
	char key;
	int value;

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