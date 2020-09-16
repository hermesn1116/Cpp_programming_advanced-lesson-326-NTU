#include <stdio.h>
#include <stdlib.h> 

int combination(int n, int m);

int main(void)
{
	int N, M;
	
	scanf("%d %d", &N, &M);
	
	if(N < M)
	{
		printf("input error");
	}
	else
	{
		printf("%d", combination(N, M));
	}	
	
	return 0;
}

int combination(int n, int m)
{
	if(n == m || m == 0)
	{
		return 1;
	}
	else
	{
		return combination(n-1, m) + combination(n-1, m-1);
	}
	
};
