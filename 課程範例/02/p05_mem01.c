#include<stdio.h>
#include<stdlib.h>

int main() {
  
  int *p;
  int n;
  
  
  scanf("%d",&n);
  //int A[n];
  
  while(1){  
	  p = (int *)malloc(sizeof(int)*n); 
	  if(p==NULL){
	  	puts("out of mem");
	  	exit(1);
	  }
	  //free(p);
  }
  
  return 0;
}
