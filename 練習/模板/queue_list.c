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
		printf("�O����t�m����!\n");
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

	printf("��C�����e: ");
	while(ptr != NULL)
	{
		printf("[%2d] ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main()
{
	int data_in; // �x�s��J���
	int data_out; // �x�s��X���
	int select; // �x�s��J�ﶵ

	while(1)
	{
		printf("(1)��J (2)���X (3)�L�X��C���e (4)���}==> ");
		scanf("%d", &select);
		switch(select)
		{
			case 1: // ��J
				printf("�п�J�s�J��C���� ==> ");
				scanf("%d", &data_in);
				if(enqueue(data_in)==-1)
					printf("��C�w��\n");
				else
					printf("�w�s�J���: %d\n", data_in);
				break;
			case 2: // ���X
				if( (data_out = dequeue()) == -1 )
					printf("��C�O�Ū�\n");
				else
					printf("���X��C���e: %d\n", data_out);
				break;
			case 3: // �L���X�Ҧ��e
				printQueue();
				break;
			case 4: 
				exit(0);
				break;
		}
	}
	return 0;
}
