#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL));
	int ans = rand()%5+1;
	int keyin;
	
	scanf("%d", &ans);
	scanf("%d", &keyin);
	
	if(keyin==ans){
		printf("bingo answer is %d\n", ans);
	}
	else{
		printf("wrong answer, answer is %d\n", ans);
	}
	return 0;
}
