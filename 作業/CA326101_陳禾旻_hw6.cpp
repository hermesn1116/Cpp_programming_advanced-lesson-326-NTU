#include <iostream>
#include <string>

using namespace std;

int linearSearch(string val, int quantity, string arr[512]);
int binarySearch(string val, int quantity, string arr[512]);
void printArray(int quantity, string arr[512]);

int main(void)
{
	char opt;
	int i, q = 0, result;
	string newD, data[512], target;
	
	do
	{
		cin >> opt;
		switch(opt)
		{
			case '1' :
				cin >> newD;
				if(q == 0)
				{
					data[0] = newD;
				}
				else
				{
					for(i = q-1; i >= 0 && data[i] > newD; i--)
					{
						data[i+1] = data[i];
					}
					data[i+1] = newD;
				}
				q++;
				
				break;
			case '2' :
				cin >> target;
				result = linearSearch(target, q, data);
				if(result != -1)
				{
					cout << "found: " << target << endl;
				}
				else
				{
					cout << "not found" << endl;
				}
				
				break;	
			case '3' :
				cin >> target;
				result = binarySearch(target, q, data);
				if(result != -1)
				{
					cout << "found: " << target << endl;
				}
				else
				{
					cout << "not found" << endl;
				}
				
				break;
			case '4' :
				printArray(q, data);
				
				break;			
		}
	} while(opt != '5');
		
	return 0;
}

int linearSearch(string val, int quantity, string arr[512])
{
	int i;
	
	for(i = 0; i < quantity; i++)
	{
		cout << i << ": " << arr[i] << endl;
		if(arr[i] == val)
		{
			return i;
		}
	}
	return -1;
};

int binarySearch(string val, int quantity, string arr[512])
{
	int low = 0, high = quantity, mid;
	
	while(low <= high)
	{
		mid = (low + high) / 2;
		cout << mid << ": " << arr[mid] << endl;
		if(arr[mid] > val)
		{
			high = mid - 1;
		}			
		else if(arr[mid] < val)
		{
			low = mid+1;
		}			
		else
		{
			return mid;
		}			
	}
	
	return -1;
};

void printArray(int quantity, string arr[512])
{
	int i;
	for(i = 0; i < quantity; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
};
