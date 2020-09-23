#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  int ans;
  int guess;
  int min=1, max=100;
  
  srand((unsigned)time(NULL));
  //ans = rand()%98+2;
  scanf("%d",&ans);
  
  while(1){
    printf("%d < ? < %d\n", min,max);
            
    scanf("%d",&guess);

    if(guess<=min||guess>=max) 
    {
      puts("out of range");
      continue;
    }    
    if(guess < ans){
      puts("wrong answer, guess larger");
      min = guess;    
    }
    else if(guess > ans){
      puts("wrong answer, guess smaller");    
      max = guess;          
    }
    else //if(ans==guess)
    {
      printf("bingo answer is %d\n", ans);
      break;
    }
  }
  
  return 0;
}
