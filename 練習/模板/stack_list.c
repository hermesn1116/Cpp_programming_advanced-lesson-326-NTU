#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���|���c���ŧi
struct stack_node 
{
	int data;
	struct stack_node *next;
};
typedef struct stack_node node;
node *stack = NULL;

//���|��ƪ��s�J
void push(int value)
{
	node *new_node;
	
	new_node = (node *)malloc(sizeof(node));
	
    if(!new_node){ //�P�_�t�m�O�_���\
	
		printf("�O����t�m����!\n");
		exit(0);
    }
    
	new_node->data = value;
	new_node->next = stack;
	stack = new_node;
}

// ���|��ƪ����X
int pop()
{
	node *top;
	int temp;

	if( stack != NULL ) //�P�_���|�O�_���Ū�
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
	printf("���|�����e: ");
	printAllNode(stack);
	printf("\n");
}

// �D�{��
int main()
{
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
				push(data_in);
				printf("�w�s�J���: %d\n", data_in);
				break;
			case 2: // ���X
				if( (data_out = pop()) == -1 )
					printf("���|�O�Ū�\n");
				else
					printf("���X���|���e: %d\n", data_out);
				break;
			case 3: // �L���X�Ҧ��e
				printStack();
				break;
			case 4: 
				exit(0);
				break;
		}
	}
	return 0;
}
