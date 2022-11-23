#include <stdio.h>
#include <stdlib.h>

int isLeap(int year);

int main(int argc, char *argv[]){
  int startYear,numLeaps,leapCount;

  leapCount = 0;

  if(argc<3||argc>3){
    printf("Usage ./startYear numLeaps\n");
    exit(1);
  }
  else{
    startYear = atoi(argv[1]);
    numLeaps = atoi(argv[2]);
  }

  while(leapCount<numLeaps){
    if(isLeap(startYear) == 1){
      printf("%d\n",startYear);
      leapCount++;
    }
    startYear++;
  }

  return 0;
}
