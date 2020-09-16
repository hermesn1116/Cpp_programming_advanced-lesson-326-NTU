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
		friend class Stack;
		friend class Queue;
};
class LinkedList
{
	public:
		LinkedList();
		void insert(int value);
		void remove(int value);
		void find(int value);
		void print();
	protected:
		node *getnode ();
		void freenode (node *p) ;
		void insert_node (node *ptr, int value);
		void delete_node(node *ptr);
		node *find_node(int num);
		int length ();

		node *head;
};

class Stack: public LinkedList
{
	public:
		void push(int value);
		int pop();
};

class Queue: public LinkedList
{
	public:
		Queue()
		{
			rear = NULL;
		}
		void enqueue(int value)
		{
			if(head==NULL)
			{
				insert_node(NULL, value);
				rear = head;
			}
			else
			{
				insert_node(rear, value);
				rear = rear->next;
			}
		}
		int dequeue()
		{
			int data;
			if(head == NULL)
			{
				cout << "Queue is empty" << endl;
				return -1;
			}
			data = head->data;
			delete_node(head);
			return data;
		}
	private:
		class node *rear;
};

void Stack::push(int value)
{
	insert_node(NULL, value);
}

int Stack::pop()
{
	int data;
	if(head == NULL)
	{
		cout << "Stack is empty" << endl;
		return -1;
	}
	data = head->data;
	delete_node(head);
	return data;
}

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
	//Stack s;
	Queue q;
	int data_in; // �x�s��J���
	int data_out; // �x�s��X���
	int select; // �x�s��J�ﶵ

	while(1)
	{
		printf("(1)��J (2)���X (3)�L�X���|���e (4)���}==> ");
		scanf("%d", &select);
		switch(select)
		{
			case 1: // ��J
				printf("�п�J�s�J���|���� ==> ");
				scanf("%d", &data_in);
				//s.push(data_in);
				q.enqueue(data_in);
				printf("�w�s�J���: %d\n", data_in);
				break;
			case 2: // ���X
				//data_out = s.pop();
				data_out = q.dequeue();
				if( data_out == -1 )
					printf("���|�O�Ū�\n");
				else
					printf("���X���|���e: %d\n", data_out);
				break;
			case 3: // �L���X�Ҧ��e
				q.print();
				//s.print();
				break;
			case 4: 
				exit(0);
				break;
		}
	}
	return 0;
}
