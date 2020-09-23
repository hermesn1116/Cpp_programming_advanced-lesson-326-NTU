#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
	int qst, ans, min = 1, max = 100;
	
	scanf("%d", &qst);
	
	do
	{
		printf("%d < ? < %d\n", min, max);
		scanf("%d", &ans);
		if(ans > min && ans < max)
		{
			if(ans < qst)
			{
				printf("wrong answer, guess larger\n");
				min = ans;
			}
			else if(ans > qst)
			{
				printf("wrong answer, guess smaller\n");
				max = ans;
			}
		}
		else
		{
			printf("out of range\n");
			continue;
		}
	} while(ans != qst);
	
	printf("bingo answer is %d", qst);
	
	return 0;
}
