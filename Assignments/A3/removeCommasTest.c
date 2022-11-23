#include <stdio.h>
#include <string.h>
#define MAXSIZE 200
int main(){
  char line[MAXSIZE];
  int removeCommas(char *);
  int numCommasRemoved;
  while((fgets(line,MAXSIZE,stdin))!=NULL){
    numCommasRemoved += removeCommas(line);
    printf(line);
  }
  printf("%d\n",numCommasRemoved);
  return 0;

}
