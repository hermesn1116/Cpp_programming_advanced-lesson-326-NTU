#include <stdio.h>
#include <stdlib.h> 

void swap(int *n1, int *n2);
int bubbleSort(int *arr);
int selectSort(int *arr);
int insertSort(int *arr);
void printArray(int *arr);

int main(void)
{
	char opt;
	int i, data[6];
	
	for(i = 0; i < 6; i++)
	{
		scanf("%d", &data[i]);
	}
	
	scanf(" %c", &opt);
	switch(opt)
	{
		case '1' :
			bubbleSort(data);
			break;
		case '2' :
			selectSort(data);
			break;
		case '3' :
			insertSort(data);
			break;
	}
	
	printArray(data);
	
	return 0;
}

void swap(int *n1, int *n2)
{
	int tmp;
	
	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
};

int bubbleSort(int *arr)
{
	int i, j;
	
	for(i = 6; i > 1; i--)
	{
		for(j = 0; j < i-1; j++)
		{
			if(arr[j+1] < arr[j])
			{
				swap(&arr[j+1], &arr[j]);
			}
		}
		printArray(arr);
	}
};

int selectSort(int *arr)
{
	int i, j, pos;

	for(i = 0; i < 5; i++)
	{
		pos = i;
		for(j= i+1; j < 6; j++)
		{
			if(arr[j] < arr[pos])
			pos = j;
		}
		swap(&arr[i], &arr[pos]);
		printArray(arr);
	}
};

int insertSort(int *arr)
{
	int i, j, key;

	for(i = 1; i < 6; i++)
	{
		key = arr[i];
		for(j = i-1; j >= 0 && arr[j] > key; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = key; 
		printArray(arr);
	}
};

void printArray(int *arr)
{
	int i;
	for(i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
};
