/*
  ID: jitenmt1
  LANG: C
  PROG: milk2
*/
#include <stdio.h>

int main()
{
  FILE* in=fopen("milk2.in", "r");
  FILE* out=fopen("milk2.out", "w");
  
  unsigned int time[1000000]={0};
  int N,i,very_start,very_end;
  fscanf(in, "%d", &N);
  int start, end;
  for(i=0; i<N; i++)
  {
    fscanf(in, "%d %d", &start, &end);
    int j;
    if(i==0)
    {
      very_start=start;
      very_end=end;
    }else{
      if(start<very_start) very_start=start;
      if(end>very_end)     very_end=end;
    }
    for(j=start; j<end; j++)
      time[j]++;
  }
  int one=0,no_one=0,temp_one=0,temp_no_one=0,prev_no=-1,j;
  for(j=very_start; j<very_end; j++)
  {
    if(time[j]==0)
    {
      if(prev_no>0)
      {
        if(temp_one>one)
          one=temp_one;
        temp_one=0;
      }
      temp_no_one++;
    }else {
      if(prev_no==0)
      {
        if(temp_no_one>no_one)
          no_one=temp_no_one;
        temp_no_one=0;
      }
      temp_one++;
    }
    prev_no=time[j];
  }

  if(temp_one>one) one=temp_one;
  if(temp_no_one>no_one) no_one=temp_no_one;
  fprintf(out, "%d %d\n", one, no_one);
  return 0;
}
