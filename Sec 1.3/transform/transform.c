/*
  ID: jitenmt1
  LANG: C
  PROG: transform
*/
#include <stdio.h>
#include <malloc.h>

int size;

int option_1(char **in, char **out)
{
  int i,j;
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
		  if(in[i][j]!=out[j][size-1-i])
				return 0;
		}
  }
	return 1;
}
int option_2(char **in, char **out)
{
  int i,j;
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
  		if(in[i][j]!=out[size-1-i][size-1-j])
				return 0;
		}
  }
	return 2;
}
int option_3(char **in, char **out)
{
  int i,j;
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
  		if(in[i][j]!=out[size-1-j][i])
				return 0;
		}
  }
	return 3;
}
void option_4(char **in, char **out)
{
  int i,j;
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			out[i][size-1-j] = in[i][j];
		}
  }
}
int option_6(char **in, char **out)
{
  int i,j;
  for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			if(in[i][j]!=out[i][j])
				return 0;
		}
  }
	return 6;
}
int option_5(char **in, char **out)
{
  char **grid_temp;
  grid_temp = (char **)malloc(size * sizeof (char *));
  int m;
  for (m=0; m < size;m++) {  
      grid_temp[m] = (char *)malloc(size * sizeof(char));
  } 
  option_4(in, grid_temp);
  if(option_6(grid_temp, out))
		return 4;
	if(option_1(grid_temp, out))
		return 5;
	if(option_2(grid_temp, out))
		return 5;
	if(option_3(grid_temp, out))
		return 5;
 	return 0;
}

int main()
{
  FILE* in=fopen("transform.in", "r");
  FILE* out=fopen("transform.out", "w");
  fscanf(in, "%d", &size);
  fseek(in, 1, SEEK_CUR);
  char **grid_in;
  char **grid_out;
  int i,j,m;
  grid_in = (char **)malloc(size * sizeof (char *));  
  for (m=0; m < size;m++) {  
      grid_in[m] = (char *)malloc(size * sizeof(char));
  } 
  grid_out = (char **)malloc(size * sizeof (char *));
  for (m=0; m < size;m++) {  
      grid_out[m] = (char *)malloc(size * sizeof(char));
  } 
  for(i=0; i<size; i++) {
    for(j=0; j<size; j++) {
			grid_in[i][j] = fgetc(in);
    }
		fseek(in, 1, SEEK_CUR);
  }
  for(i=0; i<size; i++) {
    for(j=0; j<size; j++) {
			grid_out[i][j] = fgetc(in);
    }
    fseek(in, 1, SEEK_CUR);
  }
  int answer;
	if(option_1(grid_in, grid_out)) {
		fprintf(out, "%d\n", 1);
  }else if(option_2(grid_in, grid_out)) {
		fprintf(out, "%d\n", 2);		
  }else if(option_3(grid_in, grid_out)) {
		fprintf(out, "%d\n", 3);
	}else if((answer=option_5(grid_in, grid_out))!=0) {
		fprintf(out, "%d\n", answer);
	}else if((answer=option_6(grid_in,grid_out))!=0) {
		fprintf(out, "%d\n", answer);
	}else
		fprintf(out, "%d\n", 7);
  return 0;
}
