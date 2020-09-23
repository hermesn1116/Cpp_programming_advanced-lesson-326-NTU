#include <stdio.h>
#include <stdlib.h> 

int fib(int n);

int main(void)
{
	int num, ans;
	
	scanf("%d", &num);
	
	ans = fib(num);
	
	printf("%d", ans);	
	
	return 0;
}

int fib(int n)
{
	int a, b;
	
	if(n == 1 || n == 2)
	{
		return 1;
	}
	
	else
	{
		return fib(n-1) + fib(n-2);
	}
};
