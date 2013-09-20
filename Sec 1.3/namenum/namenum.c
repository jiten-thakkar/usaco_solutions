/*
  ID: jitenmt1
  LANG: C
  PROG: namenum
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 5000
#define power(a,b) (int)pow(a,b)

int getString(char* s, FILE* names) {
  char temp;
	int i = 0;
  //printf("before char reading\n");
	while((temp=fgetc(names))!='\n' && !feof(names)) {
    //printf("%d\n",i);
		s[i++] = temp;
	}
  s[i] = '\0';
  //printf("after char reading\n");	
  //printf("%s\n",s);
	return i;
}

long nthdigit(long long x, int n)
{
    while (n--) {
        x /= 10;
    }
    return (x % 10);
}


int main()
{
	FILE* in = fopen("namenum.in", "r");
  FILE* out = fopen("namenum.out", "w");
  FILE* names = fopen("dict.txt", "r");
  int i,j,k,l;
	long long num;
  char char_map[8][3]={ {'A', 'B', 'C'},{'D', 'E', 'F'}, {'G', 'H', 'I'},
											  {'J', 'K', 'L'},{'M', 'N', 'O'}, {'P', 'R', 'S'},
                        {'T', 'U', 'V'},{'X', 'Y', 'Z'}};
  fscanf(in, "%lld", &num);
  //fclose(in);
  char dict[13]={'\0'};
  char divided_dict[14][MAX][13]={'\0'};
  int sizes[14]={0};
  /*char dict_1[MAX][13]={'\0'};
  char dict_2[MAX][13]={'\0'};
  char dict_3[MAX][13]={'\0'};
  char dict_4[MAX][13]={'\0'};
  char dict_5[MAX][13]={'\0'};
  char dict_6[MAX][13]={'\0'};
  char dict_7[MAX][13]={'\0'};*/

  //int counter=0;
	fscanf(names, "%s", dict);
	//counter++;
	//char past = dict[0];
  int index = 0, count;
	index = getString(dict, names);
	sizes[index]++;
  count = sizes[index]-1;
  strcpy(divided_dict[index][count], dict);
  while(!feof(names)) {
    //printf("in file reading\n");
	  //fscanf(names, "%s", dict);
		/*if(past != dict[0]) {
			index++;
			past = dict[0];
		}*/
		//printf("word=%s\n", dict);
		index = getString(dict, names);
  //printf("%s\n",dict);
		sizes[index]++;
    count = sizes[index]-1;
		//printf("i=%d c=%d\n", index, count);
		strcpy(divided_dict[index][count], dict);
		//fprintf(out,"%s\n",divided_dict[index][count] );
		//counter++;
	}
	//printf("after file reading\n");
	//printf("here\n");
	int num_size=1;
	//printf("here1\n");
  while((num/((long long)pow(10, num_size)))!=0) num_size++;
	//printf("here2\n");
  int size = (int)pow(3,num_size);
	//printf("here3\n");
	char word[size][num_size];
	//printf("here4\n");
  int total_words = (int)pow(3, num_size);
	//printf("here5\n");
	int start,end,cmp,mid, lastCount = 0;
	//printf("here6\n");
  /*for(i=0; i<26; i++) {
			//printf("chararcter = %c %lld %c\n", divided_dict[i][0][0], num, char_map[nthdigit(num, num_size-1)-2][0]);
		if(divided_dict[i][0][0] == char_map[nthdigit(num, num_size-1)-2][0]) {
			index = i;
			//printf("found chararcter = %c\n", divided_dict[i][0][0]);
			break;
		}
	}*/
	for(i=0; i<total_words; i++) {

		for(j=0; j<num_size; j++) {
			word[i][num_size-j-1]=char_map[nthdigit(num, j)-2][(i/(int)pow(3,j))%3];
		}
		/*if(i/(total_words/3) > lastCount) {
			lastCount++;
			index++;
		}*/
		//printf("last=%d in=%d\n", lastCount, index);
    start = 0;
		end = sizes[num_size]-1;
    while(start <= end) {	


      mid = (start+end)/2;
			//fprintf(out, "%s\n",divided_dict[num_size][mid]);
			//printf("word[i]=%s %s\n",word[i],divided_dict[num_size][mid]);
      cmp = strcmp(word[i], divided_dict[num_size][mid]);
			if(cmp<0)
				end = mid-1;
			else if(cmp>0)
				start = mid+1;
			else {
				//printf("here %d\n",i);
        fprintf(out, "%s\n", word[i]);
				break;
			}
	  }
	}
  /*past = divided_dict[0][0][0];
	for(i=0; i<total_words; i++) {
    start = 0;
		end = sizes[index]-1;
    while(start <= end) {
      mid = (start+end)/2;
      cmp = strcmp(words[mid], *divided_dict[index]);
			if(cmp<0)
				end = mid-1;
			else if(cmp>0)
				start = mid+1;
			else {
        fprintf(out, "%s\n", dict[i]);
				break;
			}
		}
	}*/

	if(ftell(out)==0)
	 	fprintf(out, "NONE\n");
  //fclose(out);
	return 0;
}
