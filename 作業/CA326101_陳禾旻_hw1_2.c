    #include <stdio.h>
#include <stdlib.h> 

int main(void)
{
	int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b[3][3] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
	int c[3][3] = {0}, i, j, k;
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			for(k = 0; k < 3; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%-5d", c[i][j]);
		}
		printf("\n");
	}	
	
	return 0;
}
