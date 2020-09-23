#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

	int income;
	int dis;
	double taxRate;
	
	scanf("%d", &income);
	
	if(income<370000){
		taxRate = 0.06;
		dis = 0;
	}
	else if(income<990000){
		taxRate = 0.13;
		dis = 25900;
	}
	else if(income<1980000){
		taxRate = 0.21;
		dis = 105100;
	}
	else if(income<3720000){
		taxRate = 0.30;
		dis = 283300;
	}
	else {
		taxRate = 0.40;
		dis = 655300;
	}
	
	printf("income %d\n", income);
	printf("tax rate %.0f%%\n", taxRate*100);
	printf("tax %.0f\n", income*taxRate);
	printf("discount %d\n", dis);
	printf("taxpay %.0f\n", income*taxRate-dis);

	return 0;
}
