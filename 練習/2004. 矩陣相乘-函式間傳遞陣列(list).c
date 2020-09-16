#include <stdio.h>
#include <stdlib.h> 

void Input2dAry(int [][3]);
void Print2dAry(int [][3]);
void MatrixMul2dAry(int [][3],int [][3],int [][3]);

int main(void)
{
	int a[3][3], b[3][3], c[3][3] = {0};
	
	Input2dAry(a);
	Input2dAry(b);
	
	MatrixMul2dAry(a, b, c);
	Print2dAry(c);
	
	return 0;
}

void Input2dAry(int arr[][3])
{
	int i, j;
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
};
 
void Print2dAry(int Arr[][3])
{
	int i, j;
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%-5d", Arr[i][j]);
		}
		printf("\n");
	}
};

void MatrixMul2dAry(int arr1[][3], int arr2[][3], int arr3[][3])
{
	int i, j, k;
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			for(k = 0; k < 3; k++)
			{
				arr3[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
} 

