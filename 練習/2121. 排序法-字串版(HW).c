#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

void swap(char *str1, char *str2);
void bubbleSort(char arr[][3]);
void selectSort(char arr[][3]);
void insertSort(char arr[][3]);
void printArray(char arr[][3]);

int main(void)
{
	char opt, data[6][3];
	int i;
	
	for(i = 0; i < 6; i++)
	{
		scanf("%s", data[i]);
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

void swap(char *str1, char *str2)
{
	char tmp[3];
	
	strcpy(tmp, str1);
	strcpy(str1, str2);
	strcpy(str2, tmp);
};

void bubbleSort(char arr[][3])
{
	int i, j;
	
	for(i = 6; i > 1; i--)
	{
		for(j = 0; j < i-1; j++)
		{
			if(strcmp(arr[j+1][3], arr[j][3]) < 0)
			{
				swap(arr[j+1][3], arr[j][3]);
			}
		}
		printArray(arr);
	}
};

void selectSort(char arr[][3])
{
	int i, j, pos;

	for(i = 0; i < 5; i++)
	{
		pos = i;
		for(j= i+1; j < 6; j++)
		{
			if(strcmp(arr[j][3], arr[pos][3]) < 0)
			pos = j;
		}
		swap(arr[i][3], arr[pos][3]);
		printArray(arr);
	}
};

void insertSort(char arr[][3])
{
	int i, j;
	char key[3];

	for(i = 1; i < 6; i++)
	{
		strcpy(key, arr[i][3]);
		for(j = i-1; j >= 0 && strcmp(arr[j][3], key) > 0; j--)
		{
			strcpy(arr[j+1][3], arr[j][3]);
		}
		strcpy(arr[j+1][3], key); 
		printArray(arr);
	}
};

void printArray(char arr[][3])
{
	int i;
	
	for(i = 0; i < 6; i++)
	{
		printf("%s ", arr[i][3]);
	}
	printf("\n");
};
