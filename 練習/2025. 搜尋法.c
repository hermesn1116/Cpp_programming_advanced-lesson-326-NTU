#include <stdio.h>
#include <stdlib.h> 

int linearSearch(int val, int quantity, int *arr);
int binarySearch(int val, int quantity, int *arr);
void printArray(int quantity, int *arr);

int main(void)
{
	char opt;
	int newD, i, data[512], q = 0, target, result;
	
	do
	{
		scanf(" %c", &opt);
		switch(opt)
		{
			case '1' :
				scanf("%d", &newD);
				if(q == 0)
				{
					data[0] = newD;
				}
				else
				{
					for(i = q-1; i >= 0 && data[i] > newD; i--)
					{
						data[i+1] = data[i];
					}
					data[i+1] = newD;
				}
				q++;
				
				break;
			case '2' :
				scanf("%d", &target);
				result = linearSearch(target, q, data);
				if(result != -1)
				{
					printf("found %d\n", target);
				}
				else
				{
					printf("not found\n");
				}
				
				break;	
			case '3' :
				scanf("%d", &target);
				result = binarySearch(target, q, data);
				if(result != -1)
				{
					printf("found %d\n", target);
				}
				else
				{
					printf("not found\n");
				}
				
				break;
			case '4' :
				printArray(q, data);
				
				break;			
		}
	} while(opt != '5');
		
	return 0;
}

int linearSearch(int val, int quantity, int *arr)
{
	int i;
	
	for(i = 0; i < quantity; i++)
	{
		printf("%d: %d\n", i, arr[i]);
		if(arr[i] == val)
		{
			return i;
		}
	}
	return -1;
};

int binarySearch(int val, int quantity, int *arr)
{
	int low = 0, high = quantity, mid;
	
	while(low <= high)
	{
		mid = (low + high) / 2;
		printf("%d: %d\n", mid, arr[mid]);
		if(arr[mid] > val)
		{
			high = mid - 1;
		}			
		else if(arr[mid] < val)
		{
			low = mid+1;
		}			
		else
		{
			return mid;
		}			
	}
	
	return -1;
};

void printArray(int quantity, int *arr)
{
	int i;
	for(i = 0; i < quantity; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
};
