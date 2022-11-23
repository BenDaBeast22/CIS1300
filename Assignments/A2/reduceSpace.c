#include <string.h>
#include <stdio.h>
#define MAX 500
#define CPY 0
#define SKIP 1

int reduceSpace(char *line){
  char character;
  int length;
  int i,state;
  int j;
  int reduceCount,reduceLength;
  char lineReduced[MAX] = {0};
  j = 0;
  state = CPY;

  reduceCount = 0;
  length = strlen(line);
  for(i = 0;i<length;i++){
    character = line[i];
    line[i] = '\0';
    if(character != ' ' && character != '\t'){
      lineReduced[j] = character;
      j++;
      state = CPY;
    }
    else if(character == ' ' && state == CPY){
      lineReduced[j] = character;
      j++;
      state = SKIP;
    }
    else if((character == ' ' || character == '\t') && state == SKIP){
      reduceCount++;
    }
    else if(character == '\t' && state == CPY){
      lineReduced[j] = ' ';
      reduceCount++;
      j++;
      state = SKIP;
    }
  }
  reduceLength = strlen(lineReduced);
  lineReduced[reduceLength] = '\0';

  strcpy(line,lineReduced);

  return reduceCount;
}
