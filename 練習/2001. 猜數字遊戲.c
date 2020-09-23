#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int main(void)
{
	int guessQ, guessA;
	
	scanf("%d", &guessQ);
	
	scanf("%d", &guessA);
	
	if(guessA == guessQ)
	{
		printf("bingo answer is %d", guessQ);
	}
	else
	{
		printf("wrong answer, answer is %d", guessQ);
	}	
	
	return 0;
}
