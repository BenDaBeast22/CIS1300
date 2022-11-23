#include <stdio.h>
#include <string.h>
#define MAXSIZE 500
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]){;
  int i,a;
  int firstCompare;
  char line[MAXSIZE];
  char lastLine[MAXSIZE] = {0};
  int duplicateCount[MAXSIZE];

  firstCompare = TRUE; /*To avoid printing first comparison between first word and nothing*/
  i = 0;

  for(a=0;a<MAXSIZE;a++){
    duplicateCount[a] = 1;
  }

  while(fgets(line,MAXSIZE,stdin) != NULL){
    if(strcmp(lastLine,line)==0){
      duplicateCount[i] += 1;
    }
    else{
      if(firstCompare == FALSE){
      printf("%03d %s",duplicateCount[i],lastLine);
      strcpy(lastLine,line);
      i++;
      }
    /*If firstCompare is true then print statement is avoided*/
    firstCompare = FALSE;
    strcpy(lastLine,line);
    }

  }
  printf("%03d %s",duplicateCount[i],line);
  return 0;

}
