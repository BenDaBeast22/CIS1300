#include <string.h>
#include <stdio.h>
int convertLowerCase(char *line){

  int length;
  int i;
  int upConvertCount = 0;

  length = strlen(line);
  for(i = 0;i<length;i++){
    if(line[i] >= 65 && line[i] <= 90){
      line[i]+=32;
      upConvertCount++;
    }
  }
  return upConvertCount;
}
