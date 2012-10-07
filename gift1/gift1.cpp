/*
 ID: jitenmt1
 LANG: C++
 PROG: gift1
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;

int N;
string* names;
int* total;

void update_balance(int amt, string* name) {
  int i;
  for(i=0; i<N; i++) {
    if(name->compare(*(names+i))==0) {
      total[i] += amt;
      return;
    }
  }
}

int main() {
 ofstream out;
 out.open("gift1.out");
 ifstream in;
 in.open("gift1.in");
 int i;
 in >> N;
 names = new string[N];
 total = new int[N];
 for(i=0; i<N; i++) {
  total[i] = 0;
 }
 for(i=0; i<N; i++) {
   in >> names[i];
 }
 string temp_name;
 while(in >> temp_name) {
   int money,people;
   in >> money;
   in >> people;
   int j;
   string person;
   for(j=0; j<people; j++) {
     in >> person;
     update_balance(money/people, &person);
   }
   if(people!=0){
       update_balance((money%people)-money, &temp_name);
   }else
     update_balance(money, &temp_name);
  // in >> temp_name;
 }

 for(i=0; i<N; i++) {
   out << names[i] << " " << total[i] << endl;
 }
 return 0;
}
