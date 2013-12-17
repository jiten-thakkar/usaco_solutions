/*
  ID: jitenmt1
  LANG: C
  PROG: calfflac
*/

#include <stdio.h>

#define MAXSIZE 20250
#define LENGTH_PER_LINE 81

int getNextChar(char* string, int index, int direction)
{
	int i;
	if(direction > 0)
	{
		for(i=index; string[i]!='\0'; i++)
			if((string[i]>=65 && string[i]<=90) || (string[i]>=97 && string[i]<=122))
				return i;
	} else
	{
		for(i=index; i>=0; i--)
			if((string[i]>=65 && string[i]<=90) || (string[i]>=97 && string[i]<=122))
				return i;
	}
	return -1;
}

void checkEvenPal(char* string, int index, int* maxLenghth, int* start, int*end)
{
	int subString[2]={0},i,j,length;
	for(i=getNextChar(string, index, -1),j=getNextChar(string, index+1, 1), length=0; i!=-1 && j!=-1; i=getNextChar(string, i-1, -1),j=getNextChar(string, j+1, 1))
	{
		int diff = string[i] - string[j];
		if(diff!=0 && diff!=32 && diff!=-32)
			break;
		subString[0] = i;
		subString[1] = j;
		length++;
	}
	length*=2;
	if(length > *maxLenghth)
	{
		*maxLenghth = length;
		*start = subString[0];
		*end = subString[1];
	} 
}

void checkOddPal(char* string, int index, int* maxLenghth, int* start, int*end)
{
	int subString[2]={0},i,j,length;
	for(i=getNextChar(string, index-1, -1),j=getNextChar(string, index+1, 1), length=0; i!=-1 && j!=-1; i=getNextChar(string, i-1, -1),j=getNextChar(string, j+1, 1))
	{
		int diff = string[i] - string[j];
		if(diff!=0 && diff!=32 && diff!=-32)
			break;
		subString[0] = i;
		subString[1] = j;
		length++;
	}
	length = (length*2)+1;
	if(length > *maxLenghth)
	{
		*maxLenghth = length;
		*start = subString[0];
		*end = subString[1];
	}
}

int main()
{
	FILE* in = fopen("calfflac.in", "r");
  FILE* out = fopen("calfflac.out", "w");
	char string[MAXSIZE]={'\0'};
	int i=0,maxLenghth=1,start=0,end=0;
	while(feof(in)==0) 
	{
		fread(string+i++, 1, 1, in);
	}

	for(i=getNextChar(string, 0, 1); i!=-1; i=getNextChar(string, i+1, 1))
	{
		checkOddPal(string, i, &maxLenghth, &start, &end);
		checkEvenPal(string, i, &maxLenghth, &start, &end);
	}

	fprintf(out, "%d\n", maxLenghth);
	for(i=start; i<=end; i++)
	{
		fprintf(out, "%c", string[i]);
	}
	fprintf(out, "\n");
	return 0;
}
