/*
  ID: jitenmt1
  LANG: C
  PROG: ride
*/
#include <stdio.h>
main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    
    char a[6], b[6];
    int num_a=1,num_b=1,i;
    fscanf(fin, "%s", a);
    fscanf(fin, "%s", b);
    //scanf("%s", &a);
    //scanf("%s", &b);
    for(i=0; i<6; i++)
    {
      if(a[i]>=65 && a[i]<=90)
        num_a*=(a[i]-64);
      if(b[i]>=65 && a[i]<=90)
        num_b*=(b[i]-64);
      //fprintf(fout, "%d \n %d\n",num_a, num_b);
    }
    //fprintf(fout, "%d \n %d\n",num_a%47, num_b%47);
    if(num_a%47 == num_b%47)
      fprintf(fout, "GO\n");
      //printf("GO\n");
    else
      fprintf(fout, "STAY\n");
      //printf("STAY\n");
    return 0;
}
