#include<stdio.h>
#define H 3
#define W 3

void Input2dAry(int [][3]);
void Print2dAry(int [][3]);
void MatrixMul2dAry(int [][3],int [][3],int [][3]);

int main() {

  int a[H][W];
  int b[H][W];
  int c[H][W] = {0};
  
  Input2dAry(a);
  Input2dAry(b);
  
  MatrixMul2dAry(c,a,b); //c=a*b
        
  Print2dAry(c);
  
  return 0;
}

void Input2dAry(int ary[][3]){
	int i,j;
	for(i=0;i<H;i++)
	    for(j=0;j<W;j++)
	      scanf("%d", &ary[i][j]);
}
void Print2dAry(int ary[][3]){
	int i,j;
	for(i=0;i<H;i++){
	    for(j=0;j<W;j++){
	      printf("%-5d", ary[i][j]);
	    }
	    puts("");
	}
}
void MatrixMul2dAry(int c[][3],int a[][3],int b[][3]){
  int i,j,k;
  
  for(i=0;i<H;i++)
    for(j=0;j<W;j++)
      for(k=0;k<W;k++)
        c[i][j]+=a[i][k]*b[k][j];
}
