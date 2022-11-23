#include <stdio.h>
#include <string.h>
int chop(char *line){
  int length;

  length = strlen(line);
  if(line[length-1]=='\n'){
    line[length-1] = '\0';
  }
  if(line == NULL){
    return(-1);
  }
  else{
    return(0);
  }

}
