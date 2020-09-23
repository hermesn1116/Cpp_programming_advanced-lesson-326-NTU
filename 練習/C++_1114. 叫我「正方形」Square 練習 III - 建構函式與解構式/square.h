#include<iostream>
#ifndef SQUARE_H
#define SQUARE_H

using namespace std;

class Square
{
	public :
		Square();
		Square(int n);
		int area();
		void setLen(int n);
		int getLen();
	private :
		int len;
};

#endif
