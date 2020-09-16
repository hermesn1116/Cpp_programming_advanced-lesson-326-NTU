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

int LinearSearch(int n, int *p, int value)
{ 
    int i;
    for(i=0; i< n; i++)
    {
    	printf("%d: %d\n",i,p[i]);
        if(p[i] == value) 
        {
            return i;  // 找到: 傳回資料位置
        }
    }
    return -1;  // 找不到: 回傳-1
}
int BinarySearch(int n, int *p, int value) 
{
    int low=0, high=n, mid;
    while(low <= high) 
    {
        mid = (low + high) / 2;
        printf("%d: %d\n",mid,p[mid]);
        if(p[mid] > value)
            high = mid - 1;
        else if(p[mid] < value)
            low = mid+1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int data[400];  // ??????
    int value;
    int n=0;
    int i,j;
    int op;
    int pos;
    
    while(1){
    	/*
    	puts("1 insert");
    	puts("2 linear search");
    	puts("3 bin search");
    	puts("4 list");
    	puts("5 quit");
    	*/
    	scanf("%d", &op);
	    switch(op){
	    	case 1:    		
			    scanf("%d", &value);
			    if(n==0)
			    	data[0] = value;
			    else{				
					for(j=n-1; j>=0 && data[j]>value; j--)  {
						data[j+1] = data[j];
					}
					data[j+1] = value;  //將key插入
				}
				n++;
			    break;
	    	case 2:    		
			    scanf("%d", &value);
			    pos =  LinearSearch(n, data, value);
			    if(pos!=-1){
			    	printf("found %d\n", data[pos]);
				}else{
					puts("not found");
				}
			    break;
	    	case 3:
			    scanf("%d", &value);
			    pos =  BinarySearch(n, data, value);
			    if(pos!=-1){
			    	printf("found %d\n", data[pos]);
				}else{
					puts("not found");
				}
			    break;
	    	case 4:    		
			    for(i=0;i<n;i++)
    				printf("%d ", data[i]);
    			puts("");
			    break;
	    	case 5:    		
			    return 0;
			    break;		    
		}
		system("pause");
		system("cls");
	}
    
    
    return 0;
}
