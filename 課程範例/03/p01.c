#include<stdio.h>
struct _test
{
    char t1[4];
    int t2;
    char t3[10];
    double t4;  
};
typedef struct _test test;
int main()
{
    int a = 10;
    int b[3] = {11,22,33};
    test c = {10,'A',"Apple",15.5};
    test d = {11,'B',"Banana",16.5};
    int e = 20;
    
    printf("a %d\n", &a);    
    printf("b %d\n", &b);
    printf("c %d\n", &c);
    printf("c.t1 %d\n", &c.t1);
    printf("c.t2 %d\n", &c.t2);
    printf("c.t3 %d\n", &c.t3);
    printf("c.t4 %d\n", &c.t4);   
    printf("d.t1 %d\n", &d.t1);
    printf("d.t2 %d\n", &d.t2);
    printf("d.t3 %d\n", &d.t3);
    printf("d.t4 %d\n", &d.t4);    
    printf("e %d\n", &d);
    
    printf("sizeof c %d\n",sizeof(c));
    
    return 0;
}
