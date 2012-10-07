/*
  ID: jitenmt1
  LANG: C
  PROG: friday
*/
#include <stdio.h>

int days[7]={0};

int calculate(int start, int year) {
  int next_day=start;

    int i,j;
    for(i=1; i<=12; i++) {
      switch(i) {
        case 2:if((year%4==0 && year%100!=0) || (year%400==0)) {
                 days[(next_day+12)%7]+=1;
                 next_day=(next_day+29)%7;
               }else {
                 days[(next_day+12)%7]+=1;                 
                 next_day=(next_day+28)%7;
               }
                 break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: days[(next_day+12)%7]+=1;
                 next_day=(next_day+31)%7;
                 break;
        case 4:
        case 6:
        case 9:
        case 11: days[(next_day+12)%7]+=1;
                 next_day=(next_day+30)%7;
                 break;
       defaut: break;  
      }
    }
  return next_day;
}

int main () {
    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");
   
    int a,i,first_day=2,year=1900;
    fscanf(fin, "%d", &a);
    for(i=0; i<a; i++) {
      first_day = calculate(first_day, year+i);
    }
    for(i=0; i<7; i++) {
      fprintf(fout, "%d", days[i]);
      if(i!=6)
        fprintf(fout, " ");
    }
    fprintf(fout, "\n");
    return 0;
}
