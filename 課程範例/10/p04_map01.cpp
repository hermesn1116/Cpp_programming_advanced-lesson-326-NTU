#include<iostream>
#include<map>

using namespace std;


int main(){
	map<string,string> m;
	string qstr;
	
	m["P"] = "Pikachu";
	m["M"] = "Mickey Mouse";
	m["H"] = "Hello kitty";
	
	cin >> qstr;
	cout << m[qstr]<<endl;
	
	return 0;
}
