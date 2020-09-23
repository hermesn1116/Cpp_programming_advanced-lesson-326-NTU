#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
	int n, *data, target, i, flag = 0;
	
	scanf("%d", &n);
	
	data = (int*)malloc(sizeof(int)*n);
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}
	
	scanf("%d", &target);
	
	for(i = 0; i < n; i++)
	{
		if(data[i] == target)
		{
			flag = 1;
		}
	}
	
	free(data);
	
	if(flag == 1)
	{
		printf("found %d", target);
	}
	else
	{
		printf("not found");
	}
	
	return 0;
}
