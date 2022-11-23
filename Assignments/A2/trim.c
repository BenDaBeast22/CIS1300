#include <stdio.h>
#include <string.h>
#define MAX 500

int trim(char *line){
  int i,j,z;
  int length;
  int start,end,trimLength;
  char character;
  char lineTrimmed[MAX] = {0};
  z = 0;
  j = 0;
  end = 0;
  length = strlen(line);
  /*Finds the index of the first character in the line*/
  for(i=0;i<length;i++){
    character = line[i];
    if(character == ' ' || character == '\t'){
      ;
    }
    else if(character != ' ' && character != '\t'){
      start = i;
      i = length;
    }
  }
  /*Finds the index of the last character in line*/
  for(i = start;i<length;i++){
    character = line[i];
    if(character != ' ' && character != '\t'){
      end = i;
    }
  }
   /* Counts through index of first character in line to index of last character in line and assigns value to lineTrimmed*/
  for(z = start; z<end+1; z++){
    lineTrimmed[j] = line[z];
    j++;
  }

  for(i=0;i<length;i++){
    line[i] = '\0';
  }
  trimLength = strlen(lineTrimmed);
  lineTrimmed[trimLength] = '\0';

  strcpy(line,lineTrimmed);
  if(line == NULL){
    return (-1);
  }
  else{
    return 0;
  }
}
