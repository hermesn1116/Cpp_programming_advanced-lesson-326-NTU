#define N 5

int main() {
  int *ptr;
  int a=10,b=20,c=30;
  int ary[] = {11,22,33,44,55};
  int d=40,e=50,f=60;
  int i;
  
  ptr = ary;
  
  for(i=0;i<N;i++){
    printf("ary[%d] => %d, mem=%p\n", i, ary[i], &ary[i]);
  }
  puts("");
  
  for(i=-9;i<N+30;i++){
    printf("ary[%d] => %d, mem=%p\n", i, ary[i], &ary[i]);
    ary[i]=0;
  }
  puts("");
  
  
  
  return 0;
}
