#include <stdio.h>
#include <stdlib.h> 

struct _student
{
	int math;
	int eng;
	int com;
};
typedef struct _student student;

int main(void)
{
	student data[5];
	char opt;
	int i, quan = 0;
	double avgM = 0, avgE = 0, avgC = 0, avgP = 0;
	
	do
	{
		scanf(" %c", &opt);
		switch(opt)
		{
			case '1' :
				 if(quan < 5)
				 {
				 	scanf("%d %d %d", &data[quan].math, &data[quan].eng, &data[quan].com);
				 	quan += 1;
				 }
				 else
				 {
				 	printf("out of range");
				 }
				 
				 break;
			case '2' :
				scanf("%d", &i);
				if(i-1 <= quan && i > 0)
				{
					printf("%d\n%d\n%d\n", data[i-1].math, data[i-1].eng, data[i-1].com);
				}
				else
				{
					printf("not found");
				}
				
				break;
			case '3' :
				scanf("%d", &i);
				if(i-1 <= quan && i > 0)
				{
					scanf("%d %d %d", &data[i-1].math, &data[i-1].eng, &data[i-1].com);
				}
				else
				{
					printf("not found");
				}
				
				break;
			case '4' :
				for(i = 1; i <= quan; i++)
				{
					printf("%d\n%d\n%d\n", data[i-1].math, data[i-1].eng, data[i-1].com);
				}
					
				break;
			case '5' :
				for(i = 0; i < quan; i++)
				{
					avgM += data[i].math;
					avgE += data[i].eng;
					avgC += data[i].com;
				}
				
				avgM /= quan;
				avgE /= quan;
				avgC /= quan;
				
				printf("%.2lf\n%.2lf\n%.2lf\n", avgM, avgE, avgC);
				
				break;
			case '6' :
				scanf("%d", &i);
				if(i-1 <= quan && i > 0)
				{
					avgP += data[i-1].math+data[i-1].eng+data[i-1].com;
					avgP /= 3;
					printf("%.2lf\n", avgP);
				}
				
				break;
		}
	} while(opt != '0');
	
	return 0;
	
}
