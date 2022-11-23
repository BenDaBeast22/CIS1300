#include <string.h>
int replaceDigits(char *line){
  int length;
  int i;
  int numDigitsReplaced = 0;

  length = strlen(line);
  for(i = 0;i<length;i++){
    if(line[i] >= 48 && line[i] <= 57){
      line[i] = ' ';
      numDigitsReplaced++;
    }
  }
  return numDigitsReplaced;
}
