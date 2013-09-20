/*
  ID: jitenmt1
  LANG: C++
  PROG: palsquare
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef basic_string<char> string;

const char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7','8','9','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

bool checkPalin(string square) {
	for(unsigned i=0,j=square.length()-1; i<square.length()/2; i++, j--) {
		if(square.at(i) != square.at(j))
			return false;
	}
	return true;
}

string numberWithBase(int num, int base) {
	string square;
  int devision;
	while((devision = num / base) > 0) {
		square.push_back(digits[num % base]);
		num = devision;
	}
  square.push_back(digits[num % base]);
	return square;
}

string reverseString(string old) {
	string newString;
	for(int i=old.length()-1; i>=0; i--) {
		newString.push_back(old.at(i));
	}
	return newString; 
}

int main ()
{
	ifstream in;
	ofstream out;

	in.open("palsquare.in");
	out.open("palsquare.out");

	int base;
	in >> base;
	for(int i=1; i<=300; i++) {
		string square = numberWithBase(i*i, base);
		if(checkPalin(square))
			out <<reverseString(numberWithBase(i, base))<<" "<<square<<endl;
	}
}
