#include<stdio.h>
#include<stdlib.h> 

int main(void)
{
	int N, J, K, L, M;
	
	scanf("%d", &N);
	
	if(N <= 370000)
	{
		J = 6;
		L = 0; 
	}
	else if(N > 370000 && N <= 990000)
	{
		J = 13;
		L = 25900;
	}
	else if(N > 990000 && N <= 1980000)
	{
		J = 21;
		L = 105100;
	}
	else if(N > 1980000 && N <= 3720000)
	{
		J = 30;
		L = 283300;
	}
	else
	{
		J = 40;
		L = 655300;
	}
	
	K = N * J / 100;
	M = K - L;
	
	printf("income %d\ntax rate %d%%\ntax %d\ndiscount %d\ntaxpay %d", N, J, K, L, M);
	
	return 0;
}
