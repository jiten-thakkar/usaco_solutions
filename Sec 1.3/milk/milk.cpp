/*
  ID: jitenmt1
  LANG: C++
  PROG: milk
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

#define f(i,n) for(int i=0; i<n;i++)

int farmers, number, size = 2, sum=0;

int main()
{
	ifstream in("milk.in");
	ofstream out("milk.out");

	int amount;
	in >> amount >> farmers;
	number = farmers;
	vector< vector<int> > prices(farmers, vector<int>(size));
	while(number--)
	{
		in >> prices[number][0] >> prices[number][1];
	}
	sort(prices.begin(), prices.begin() + farmers);
	for(int i=0; i<farmers; i++)
	{
		int temp_amount;
		if(amount == 0)
			break;
		if(prices[i][1] >= amount)
			temp_amount = amount;
		 else
			temp_amount = prices[i][1];
		sum += prices[i][0] * temp_amount;
		amount -= temp_amount;
	}
	out << sum << endl;	
}
