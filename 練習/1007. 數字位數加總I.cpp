#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int num, sum = 0, i;
	
	cin >> num;
	
	for(i = 0; i < 4; i++)
	{
		sum += num % 10;
		num /= 10;
	}
	
	cout << sum;
	
	return 0;
}
