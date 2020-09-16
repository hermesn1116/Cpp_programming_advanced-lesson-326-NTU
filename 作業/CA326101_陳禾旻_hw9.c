#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int binarySearch(int val, int quantity, int *arr);

int main(void)
{
	int cardset[52] = {0}, i, top = 0, cardNo; 
	
	srand(time(NULL));
	while(1)
	{
		if(top == 52)
		{
			break;
		}
		else
		{
			cardNo = (rand()%52)
			if(binarySearch(cardNo, top, cardset) == -1)
			{
				
			}
		}
		
	}
	
	return 0;
}

int push(int value, int top, int *stack)
{
	if(top == 51)
	{
		return -1;
	}
	top++;
	stack[top] = value;
	return 1;
}

int binarySearch(int val, int quantity, int *arr)
{
	int low = 0, high = quantity, mid;
	
	while(low <= high)
	{
		mid = (low + high) / 2;
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
