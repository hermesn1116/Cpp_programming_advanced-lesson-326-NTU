#include <iostream>
#include <cstdlib>
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
		bool find(int value);
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

node *LinkedList::getnode () /* 此函數產生一個新節點 */
{
	node *p;
	p = new node;
	if ( p == NULL)
	{
		cout << "記憶體不足" << endl;
		exit(1);
	}
	return(p);
}
void LinkedList::freenode (node *p) /* 此函數將節點還給記憶體 */
{
	delete p;
}

void LinkedList::insert_node ( node *ptr, int value)
{ 
	node *new_node;            /* 新節點指標變數 */
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

void LinkedList::delete_node(node *ptr)
{
	node *previous; /* 指向前一節點 */
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
node *LinkedList::find_node(int num)
{
	node *ptr;
	ptr = head; /* 指向串列起始 */
	while ( ptr != NULL ) /* 走訪串列 */
	{ 
		if ( ptr->data == num ) /* 找尋data */
		return (ptr);
		ptr = ptr->next; /* 指向下一節點 */
	} 
	return (ptr);
}
int LinkedList::length () /* 此函數計算節點之鏈結長度 */
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
}

void LinkedList::remove(int value)
{
	node *ptr;
	ptr = find_node(value);
	if(ptr != NULL)
	{
		delete_node(ptr);
	}
}

bool LinkedList::find(int value)
{
	node *ptr;
	ptr = find_node(value);
	if(ptr != NULL)
	{
		return true;
	}
	else
	{
		return false;
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
	LinkedList *list;
	int N, K, M, i;
	bool res;

	cin >> N;
	list = new LinkedList[N];
	
	for(i = 0; i < N; i++)
	{
		int value;
		
		cin >> value;
		while(value != -1)
		{
			list[i].insert(value);
			cin >> value;
		} 		
	}
	
	for(i = 0; i < N; i++)
	{
		list[i].print();		
	}
	
	cin >> K;
	cout << "Delete " << K << endl;
	for(i = 0; i < N; i++)
	{
		list[i].remove(K);
	}
	
	for(i = 0; i < N; i++)
	{
		list[i].print();		
	}
	
	cin >> M;
	cout << "Find " << M << endl;
	for(i = 0; i < N; i++)
	{
		res = list[i].find(M);
		if(res)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}	
	
	return 0;
}
