/*
 ID: jitenmt1
 LANG: C++
 PROG: beads
*/

#include <iostream>
#include <fstream>

using namespace std;

char find_curr_char(char* nec, int curr_index, int size) {
  int i = curr_index;
  if(nec[i]=='w') {
    while(nec[(i+1)%size]=='w') {
      i=(i+1)%size;
      if(i==curr_index)
        return 'b';
    }
    return nec[(i+1)%size];
  }else
    return nec[i];
}

int main() {
 ofstream out;
 out.open("beads.out");
 ifstream in;
 in.open("beads.in");
 int size,i;
 in >> size;
 char* nec = new char[size];
 int* max_chain = new int[size]();
 for(i=0; i<size; i++) {
   in >> nec[i];
 }
 for(i=0; i<size; i++) {
   int j=i;
   char curr_char=find_curr_char(nec, i, size);
   char original_curr_char = curr_char;
   while(1) {
     if(nec[j]==curr_char || nec[j]=='w')
       max_chain[i]++;
     else{
       if(curr_char==original_curr_char) {
         max_chain[i]++;
         curr_char=nec[j];
       }else
         break;
     }
     j=(j+1)%size;
     if(j==i)
       break;
   }
 }
 int max=0;
 for(i=0; i<size; i++) {
   if(max_chain[i]>max)
     max=max_chain[i];
 }
 out << max << endl;
 return 0;
}
