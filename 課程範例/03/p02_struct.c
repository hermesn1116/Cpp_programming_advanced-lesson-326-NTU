#include<stdio.h>

#define N 5

struct student
{
  int math;
  int eng;
  int pc;
};
typedef struct student score;

int main() {
  score s[N], sum={0};
  int i;
  
  for(i=0;i<N;i++){
      scanf("%d", &s[i].math);
      scanf("%d", &s[i].eng);
      scanf("%d", &s[i].pc);
  }
  
  for(i=0;i<N;i++){
      sum.math += s[i].math;
      sum.eng += s[i].eng;
      sum.pc += s[i].pc;
  }
  
  printf("%.2f\n", (double)sum.math/N);
  printf("%.2f\n", (double)sum.eng/N);
  printf("%.2f\n", (double)sum.pc/N);  
  
  return 0;
}
