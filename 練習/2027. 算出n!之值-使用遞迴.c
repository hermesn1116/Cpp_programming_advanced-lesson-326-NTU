#include <stdio.h>
#include <stdlib.h> 

int fact(int n);

int main(void)
{
	int N;
	
	scanf("%d", &N);
	
	printf("%d", fact(N));
	
	return 0;
}

int fact(int n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n * fact(n-1);
	}
};
