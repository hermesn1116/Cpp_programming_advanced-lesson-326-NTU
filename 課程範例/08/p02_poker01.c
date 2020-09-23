#include<stdio.h>

int main(){
	
	int i;
	for(i=0;i<52;i++){
		printf("%d %c%d\n", i, i/13+3, i%13+1);
	}
	return 0;
}
