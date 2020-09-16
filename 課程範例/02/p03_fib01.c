#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double fib(int n, double ct[]){
  if(n==1||n==2)
    return 1;

  if(ct[n-1])
    return ct[n-1];
  
  double a = fib(n-1, ct);
  double b = fib(n-2, ct);
  ct[n-1] = a+b;
  return a+b;  
}

int main() {  
  int n;
  double *ct;
  scanf("%d", &n);
  ct = (double *)malloc(sizeof(double)*n);
  memset(ct,0,sizeof(double)*n);
  printf("fib(%d) = %.0f\n",n,fib(n,ct));
  free(ct);
  return 0;
}
