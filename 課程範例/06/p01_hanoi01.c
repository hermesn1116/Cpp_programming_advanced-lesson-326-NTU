#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void hanoi (int n, char from, char mid, char to,int *ct)
{   // ????n????
    if(n==0)
        return ;
    // ???n-1?????”???”
    hanoi(n-1,from, to, mid,ct);
    // ?????”???”
    printf("plate %d from %c -> %c\n",n,from,to);
    ct[n-1]++;
    // ???n-1????”???”???
    hanoi(n-1,mid, from, to,ct);
}

int main()
{
    int n,i;
    scanf("%d", &n);
    int *ct = (int *)malloc(sizeof(int)*n);
	memset(ct, 0, sizeof(int)*n);
    
    hanoi(n, 'A','B','C',ct);
    
    puts("");
    for(i=0;i<n;i++){
    	printf("plate %d = %d\n",i+1,ct[i]);
	}
    
    return 0;
}
