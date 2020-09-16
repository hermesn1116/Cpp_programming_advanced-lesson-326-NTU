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
node<T> *LinkedList<T>::getnode () /* 此函數產生一個新節點 */
{
	node<T> *p;
	p = new node<T>;
	if ( p == NULL)
	{
		cout << "記憶體不足" << endl;
		exit(1);
	}
	return(p);
}

template <class T>
void LinkedList<T>::freenode (node<T> *p) /* 此函數將節點還給記憶體 */
{
	delete p;
}

template <class T>
void LinkedList<T>::insert_node ( node<T> *ptr, T &value)
{ 
	node<T> *new_node;            /* 新節點指標變數 */
	new_node = getnode();    /* 建立新節點,取得一個可用節點 */
	new_node->data = value; /* 建立節點內容 */
	new_node->next = NULL; /* 設定指標初值 */
	
	if ( ptr == NULL ) /* 指標ptr是否是NULL */
	{
		/* 第一種情況: 插入第一個節點 */
		new_node->next = head; /* 新節點成為串列開始 */
		head = new_node;
	}
	else
	{
		if ( ptr->next == NULL ) /* 是否是串列結束 */
			/* 第二種情況: 插入最後一個節點 */
			ptr->next = new_node; /* 最後指向新節點 */
		else
		{
			/* 第三種情況: 插入成為中間節點 */
			new_node->next = ptr->next; /* (3) 新節點指向下一節點 (3)*/
			ptr->next = new_node; /* 節點ptr指向新節點 (4)*/
		}
	}
}

template <class T>
void LinkedList<T>::delete_node(node<T> *ptr)
{
	node<T> *previous; /* 指向前一節點 */
	if ( ptr == head ) /* 是否是串列開始 */
	/* 第一種情況: 刪除第一個節點 */
	{
		head = head->next;
	}
	else
	{
		previous = head;
		while ( previous->next != ptr ) /* 找節點ptr的前節點 */
			previous = previous->next;
		if ( ptr->next == NULL ) /* 是否是串列結束 */
		/* 第二種情況: 刪除最後一個節點 */
			previous->next = NULL; /* 最後一個節點 */
		else
		/* 第三種情況: 刪除中間節點 */
			previous->next = ptr->next; /* 圖(3)之步驟(1) */
	}
	freenode(ptr); /* 此函數將節點歸還給記憶體 */
}
template <class T>
node<T> *LinkedList<T>::find_node(T &num)
{
	node<T> *ptr;
	ptr = head; /* 指向串列起始 */
	while ( ptr != NULL ) /* 走訪串列 */
	{ 
		if ( ptr->data == num ) /* 找尋data */
		return (ptr);
		ptr = ptr->next; /* 指向下一節點 */
	} 
	return (ptr);
}
template <class T>
int LinkedList<T>::length () /* 此函數計算節點之鏈結長度 */
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
	cout << "資料插入成功!" <<  endl;
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
		cout << "資料已刪除!" <<  endl;
	}
	else
	{
		cout << "無此資料!" <<  endl;
	}
}

template <class T>
void LinkedList<T>::find(T &value)
{
	node<T> *ptr;
	ptr = find_node(value);
	if(ptr != NULL)
	{
		cout << "找到節點資料: " <<  ptr->data << endl;
	}
	else
	{
		cout << "找不到該節點資料" << endl;
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
		cout << "i: 插入" << endl;
		cout << "d: 刪除" << endl;
		cout << "f: 尋找" << endl;
		cout << "l: 列印" << endl;
		cout << "e: 離開" << endl;
		cout << "> ";
		key = getche();
		cout << endl;
		switch(key)
		{
			case 'i':
				cout << "輸入插入資料內容: ";
				cin >> value;
				list.insert(value);
				break;
			case 'd':
				cout << "輸入刪除資料內容: ";
				cin >> value;
				list.remove(value);
				break;
			case 'f':
				cout << "輸入尋找資料內容: ";
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
				cout << "輸入值錯誤!" << endl; 
		}
		cout << endl; 
	}
	return 0;
}