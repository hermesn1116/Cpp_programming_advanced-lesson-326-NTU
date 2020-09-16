#include<iostream>
#include<list>

using namespace std;

template <class T>
void printList(list<T> &lst)
{
    class list<T>::iterator it;
    cout << "[";
    if(lst.size()>0){  
        it=lst.begin();
        cout <<"'"<<*it<<"'";
        it++;
        for(;it!=lst.end();it++){
            cout << ", "<<"'"<<*it<<"'"  ;
        }
    }
    cout << "]\n";
}

int main(){
	string books[] = {"Book1", "Book2", "Book6", "Book4", "Book5"};
	list<string> st(books,books+5);
	
	st.push_back("Book3");
	st.sort();
	
	printList(st);
		

	
	return 0;
}
