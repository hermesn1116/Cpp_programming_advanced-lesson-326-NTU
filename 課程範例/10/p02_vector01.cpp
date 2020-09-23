#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> v;
	vector<int>::iterator it;
	int n;
	
	cin >> n;
	for(int i=n;i>0;i--){
		cout << "data " << i <<endl;
		v.push_back(i);
	}
	cout << endl;
	for(int i=0;i<n;i++){
		cout << "data " << v.back() << endl;
		v.pop_back();
	}
	

	
	return 0;
}
