#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 堆疊結構的宣告
struct stack_node 
{
	int data;
	struct stack_node *next;
};
typedef struct stack_node node;
node *stack = NULL;

//堆疊資料的存入
void push(int value)
{
	node *new_node;
	
	new_node = (node *)malloc(sizeof(node));
	
    if(!new_node){ //判斷配置是否成功
	
		printf("記憶體配置失敗!\n");
		exit(0);
    }
    
	new_node->data = value;
	new_node->next = stack;
	stack = new_node;
}

// 堆疊資料的取出
int pop()
{
	node *top;
	int temp;

	if( stack != NULL ) //判斷堆疊是否為空的
	{
		top = stack;
		stack = stack->next;
		temp = top->data;
		free(top);
		return temp;
	}
	else 
		return -1;
}

void printAllNode(node *s)
{
	if(s == NULL)
	{
		return;
	}
	else
	{
		printAllNode(s->next);
		printf("[%2d] ",  s->data);
	}
}

void printStack()
{
	printf("堆疊的內容: ");
	printAllNode(stack);
	printf("\n");
}

// 主程式
int main()
{
	int data_in; // 儲存輸入資料
	int data_out; // 儲存輸出資料
	int select; // 儲存輸入選項

	while(1)
	{
		printf("(1)輸入 (2)取出 (3)印出堆疊內容 (4)離開==> ");
		scanf("%d", &select);
		switch(select)
		{
			case 1: // 輸入
				printf("請輸入存入堆疊的值 ==> ");
				scanf("%d", &data_in);
				push(data_in);
				printf("已存入資料: %d\n", data_in);
				break;
			case 2: // 取出
				if( (data_out = pop()) == -1 )
					printf("堆疊是空的\n");
				else
					printf("取出堆疊內容: %d\n", data_out);
				break;
			case 3: // 印內出所有容
				printStack();
				break;
			case 4: 
				exit(0);
				break;
		}
	}
	return 0;
}
