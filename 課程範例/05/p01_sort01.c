#include <stdio.h>
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
void print(int n, int *p)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}

void bsort(int n, int *data){
	//int data[5] = {34,12,5,66,1};  // ??????
    int i, j; 
    //int n=5;

    for(i=n; i>1; i--) 
    {
        for(j=0; j<i-1; j++)
        {
            if(data[j+1] < data[j]) 
            {
               swap(&data[j+1], &data[j]);
            }
        }
        print(n, data);
    }
    //print(n, data);
}

void ssort(int n, int *data){
    int i, j, pos;  // pos: ?????????
    for(i=0; i<n-1; i++)
    {
        pos = i;
        for(j=i+1; j<n; j++) // ?????
        {
            if(data[j] < data[pos]) 
                pos = j; 
        }
        swap(&data[i], &data[pos]);
        print(n, data);
    }
}

void isort(int n, int *data){
    int i, j; 
    int key;  // ????????
    for( i=1; i<n; i++) 
    {
        key=data[i];
        for(j=i-1; j>=0 && data[j]>key; j--)
        {
            data[j+1] = data[j];
        }
        data[j+1] = key;  //?key??
        print(n, data);
    }
}
int main()
{
    int data[6];  // ??????
    int n=6;
    int i;
    int op;
    
    for(i=0;i<n;i++)
    	scanf("%d", data+i);
    
    scanf("%d", &op);
    switch(op){
    	case 1:    		
		    bsort(n,data);
		    break;
    	case 2:    		
		    ssort(n,data);
		    break;
    	case 3:    		
		    isort(n,data);
		    break;		    
	}
    print(n, data);
    
    return 0;
}
