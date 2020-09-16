#include <iostream>
#include <string>
using namespace std;

void BubbleSort_Double(int n, double A[])
{
	double temp;
	int i,j;
	for(i=n-1; i>1; i--)	//for(i=0; i<n-1; i++)
	{
		for(j=0;j<i; j++)	//for(j=0; j<n-1; j++)
		{
			if(A[j] > A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}

void BubbleSort_Int(int n, int A[])
{
	int temp;
	int i,j;
	for(i=n-1; i>1; i--)	//for(i=0; i<n-1; i++)
	{
		for(j=0;j<i; j++)	//for(j=0; j<n-1; j++)
		{
			if(A[j] > A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}
void BubbleSort_Char(int n, char A[])
{
	char temp;
	int i,j;
	for(i=n-1; i>1; i--)	//for(i=0; i<n-1; i++)
	{
		for(j=0;j<i; j++)	//for(j=0; j<n-1; j++)
		{
			if(A[j] > A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}
void BubbleSort_String(int n, string A[])
{
	string temp;
	int i,j;
	for(i=n-1; i>1; i--)	//for(i=0; i<n-1; i++)
	{
		for(j=0;j<i; j++)	//for(j=0; j<n-1; j++)
		{
			if(A[j] > A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}

void PrintArray_Int(int n, int A[])
{
	int i;
	for(i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
}

void PrintArray_Double(int n, double A[])
{
	int i;
	for(i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
}

void PrintArray_Char(int n, char A[])
{
	int i;
	for(i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
}

void PrintArray_String(int n, string A[])
{
	int i;
	for(i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
}
int main()
{
	int n=5;
	int A1[5]={12,33,2,4,22};
	double A2[5]={12.43, 12.33, 2.4 ,4.66 ,22.1};
	char A3[5]={'G','B','H','Z','Q'};
	string A4[5]={"Joe", "John", "Andy", "Mary", "Bob"};

	BubbleSort_Int(n, A1);
	BubbleSort_Double(n, A2);
	BubbleSort_Char(n, A3);
	BubbleSort_String(n, A4);

	PrintArray_Int(n, A1);
	PrintArray_Double(n, A2);
	PrintArray_Char(n, A3);
	PrintArray_String(n, A4);

	return 0;
}
