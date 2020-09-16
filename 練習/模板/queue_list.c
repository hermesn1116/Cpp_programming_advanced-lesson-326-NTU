#include <stdio.h>
#include <stdlib.h>

struct queue_node
{
	int data;
	struct queue_node *next;
};
typedef struct queue_node node;
node *front = NULL;
node *rear = NULL;

int enqueue(int value)
{
	node *new_node;

	new_node = (node *)malloc(sizeof(node));
	if( !new_node )
	{
		printf("記憶體配置失敗!\n");
		exit(0);
	}
	new_node->data = value;
	new_node->next = NULL;
	if(front==NULL)
		front = new_node;
	else
		rear->next = new_node;
	rear = new_node;
	return 1;
}

int dequeue()
{
	node *top;
	int temp;

	if(front != NULL)
	{
		top = front;
		front = front->next;
		temp = top->data;
		free(top);
		return temp;
	}
	else
		return -1;
}

void printQueue()
{
	node *ptr = front;

	printf("佇列的內容: ");
	while(ptr != NULL)
	{
		printf("[%2d] ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main()
{
	int data_in; // 儲存輸入資料
	int data_out; // 儲存輸出資料
	int select; // 儲存輸入選項

	while(1)
	{
		printf("(1)輸入 (2)取出 (3)印出佇列內容 (4)離開==> ");
		scanf("%d", &select);
		switch(select)
		{
			case 1: // 輸入
				printf("請輸入存入佇列的值 ==> ");
				scanf("%d", &data_in);
				if(enqueue(data_in)==-1)
					printf("佇列已滿\n");
				else
					printf("已存入資料: %d\n", data_in);
				break;
			case 2: // 取出
				if( (data_out = dequeue()) == -1 )
					printf("佇列是空的\n");
				else
					printf("取出佇列內容: %d\n", data_out);
				break;
			case 3: // 印內出所有容
				printQueue();
				break;
			case 4: 
				exit(0);
				break;
		}
	}
	return 0;
}
