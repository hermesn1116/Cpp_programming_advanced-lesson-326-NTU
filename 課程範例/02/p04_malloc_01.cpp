#include<stdio.h>
#include<stdlib.h>

int main() {
  
  int *p;
  int n, i, qnum;
  int flag = 1;
  
  scanf("%d",&n);
  p = (int *)malloc(sizeof(int)*n); 
  
  for(i=0;i<n;i++)
    scanf("%d",&p[i]);
  
  scanf("%d",&qnum);
  
  for(i=0;i<n;i++){
      if(p[i] ==qnum){
        printf("found %d\n",qnum);
        flag = 0;
      }
  }
  
  if(flag)
    puts("not found");
  
  free(p);
  
  return 0;
}
