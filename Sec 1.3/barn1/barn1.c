/*
  ID: jitenmt1
  LANG: C
  PROG: barn1
*/

#include <stdio.h>

void swap(int* list, int from, int to)
{
	if(from == to)
		return;
	list[from] += list[to];
	list[to] = list[from] - list[to];
	list[from] -= list[to];
}

void quick_sort(int* list, int first, int last)
{
  int i;
	if(first >= last-1)
		return;
	int pivot = (first+last)/2;
	int pivotNew = first;
	swap(list, pivot, last-1);
	for(i=first; i<last-1; i++)
	{
		if(list[i] > list[last-1])
			swap(list, pivotNew++, i);
	}
	swap(list, pivotNew, last-1);
	quick_sort(list, first, pivotNew);
	quick_sort(list, pivotNew+1, last);
}

int main()
{
	FILE* in = fopen("barn1.in", "r");
  FILE* out = fopen("barn1.out", "w");
  int i;
	int M,S,C;
	int prev,present;
  int not_covered=0;
	int gaps[100]={0};
  int cows[200]={0};
	int  j=0;
	fscanf(in, "%d", &M);
	fscanf(in, "%d", &S);
	fscanf(in, "%d", &C);
	for(i=0; i<C; i++)
	{
		fscanf(in, "%d", &cows[i]);
	}
  quick_sort(cows, 0, C);
  prev = cows[0];
	not_covered+=(cows[C-1]-1);
  for(i=1; i<C; i++)
  {
		present = cows[i];
		if(present!=prev-1)
			gaps[j++] = prev-present-1;
		prev = present;      
	}
	not_covered+=S-cows[0];
	quick_sort(gaps, 0, j);
	for(i=0; i<M-1; i++)
	{
		not_covered+=gaps[i];
	}
	fprintf(out, "%d\n", S-not_covered);
	return 0;
}
