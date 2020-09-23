#include <stdio.h>
#include <stdlib.h> 

void hanoi(int n, char from, char mid, char to, int *arr);

int main(void)
{
	int n, *data, i;	
		
	scanf("%d", &n);
	data = (int*)malloc(sizeof(int)*n);
	memset(data, 0, sizeof(int)*n);		
	hanoi(n, 'A', 'B', 'C', data);
	
	printf("\n");
	for(i = 0; i < n; i++)
	{
		printf("plate %d = %d\n", i+1, data[i]);
	}
	
	free(data);
	
	return 0;
}

void hanoi(int n, char from, char mid, char to, int *arr)
{
		
	if(n == 0)
	{
		return ;
	}
	
	hanoi(n-1, from, to, mid, arr);
	printf("plate %d from %c -> %c\n", n, from, to);
	arr[n-1]++;
	hanoi(n-1, mid, from, to, arr);
};
