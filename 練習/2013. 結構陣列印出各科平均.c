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
	int i;
	double avgM = 0, avgE = 0, avgC = 0;
	
	for(i = 0; i < 5; i++)
	{
		scanf("%d %d %d", &data[i].math, &data[i].eng, &data[i].com);
		avgM += data[i].math;
		avgE += data[i].eng;
		avgC += data[i].com;
	}
	
	avgM /= 5;
	avgE /= 5;
	avgC /= 5;
	
	printf("%.2lf\n%.2lf\n%.2lf\n", avgM, avgE, avgC);
	
	return 0;
}
