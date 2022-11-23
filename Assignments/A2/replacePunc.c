#include <string.h>
int replacePunc(char *line){
  int puncReplaced = 0;
  int length;
  int i;

  length = strlen(line);
  for(i = 0;i<length;i++){
    if((line[i] >= 33 && line[i] <= 47)||(line[i] >= 58 && line[i] <= 64)||(line[i] >= 91 && line[i] <=96)||(line[i] >= 123 && line[i] <= 255)){
      line[i] = ' ';
      puncReplaced++;
    }
  }
  return puncReplaced;
}
