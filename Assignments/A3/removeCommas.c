#include <string.h>
#define MAXSIZE 200
int removeCommas(char *line){
  int length = 0;
  int i;
  int j = 0;
  int commasReplaced = 0;
  char reduceCommas[MAXSIZE] = {0};

  length = strlen(line);

  for(i=0; i<length; i++){
    if(line[i] != ','){
      reduceCommas[j] = line[i];
      line[i] = '\0';
      j++;
    }
    else{
      commasReplaced++;  
    }
  }
  reduceCommas[length] = '\0';
  strcpy(line,reduceCommas);
  return commasReplaced;
}
