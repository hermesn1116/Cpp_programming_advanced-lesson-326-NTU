#include <iostream>
#include <string>

using namespace std;

void swap(string &str1, string &str2);
void bubbleSort(string arr[6]);
void selectSort(string arr[6]);
void insertSort(string arr[6]);
void printArray(string arr[6]);

int main(void)
{
	char opt;
	string data[6];
	int i;
	
	for(i = 0; i < 6; i++)
	{
		cin >> data[i];
	}
	
	cin >> opt;
	switch(opt)
	{
		case '1' :
			bubbleSort(data);
			break;
		case '2' :
			selectSort(data);
			break;
		case '3' :
			insertSort(data);
			break;
	}
	
	printArray(data);
	
	return 0;
}

void swap(string &str1, string &str2)
{
	string tmp;
	
	tmp = str1;
	str1 = str2;
	str2 = tmp;
};

void bubbleSort(string arr[6])
{
	int i, j;
	
	for(i = 6; i > 1; i--)
	{
		for(j = 0; j < i-1; j++)
		{
			if(arr[j+1] < arr[j])
			{
				swap(arr[j+1], arr[j]);
			}
		}
		printArray(arr);
	}
};

void selectSort(string arr[6])
{
	int i, j, pos;

	for(i = 0; i < 5; i++)
	{
		pos = i;
		for(j= i+1; j < 6; j++)
		{
			if(arr[j] < arr[pos])
			pos = j;
		}
		swap(arr[i], arr[pos]);
		printArray(arr);
	}
};

void insertSort(string arr[6])
{
	int i, j;
	string key;

	for(i = 1; i < 6; i++)
	{
		key = arr[i];
		for(j = i-1; j >= 0 && arr[j] > key; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = key; 
		printArray(arr);
	}
};

void printArray(string arr[6])
{
	int i;
	
	for(i = 0; i < 6; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
};
