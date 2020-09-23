#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

void swap(char str1[3], char str2[3])
{
	char tmp[3];
	
	strcpy(tmp, str1);
	strcpy(str1, str2);
	strcpy(str2, tmp);
};

int main(void)
{
	char n1 = {'h', 'i', 'i'}, n2 = {'f', 'i', 'i'};
	
	char tmp[4];
	
	strcpy(tmp, n1);
	//strcpy(n1, n2);
	//strcpy(n2, tmp);
	
	printf("%s\n/", tmp);
	
	return 0;
}
