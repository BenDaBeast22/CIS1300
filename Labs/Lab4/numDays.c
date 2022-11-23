#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

int main(int argc, char *argv[]){

  int dd = 0;
  int mm = 0;
  int yyyy = 0;
  int x = 0;
  int leapyear;

  int dayofyear[12] = {1,32,60,91,121,152,182,213,244,274,305,335};
  int monthLength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  leapyear = FALSE;

  if(argc<5){
    printf("Usage ./numDays dd mm yyyy x\n");
    exit(1);
  }
  else{
    dd = atoi(argv[1]);
    mm = atoi(argv[2]);
    yyyy = atoi(argv[3]);
    x = atoi(argv[4]);
  }
  /*Add day if in leap year range
  yeardiff = yyyy2-yyyy1;
  leapCount = 0;
  if(yeardiff==0){
    if((mm1<=2)&&(mm2>2)){
      for(i = yyyy1;i<yyyy1+1;i++){
        if(i%4==0){
          if(i%400 == 0){
            leapCount++;
          }
          else if(i%100==0){
            ;
          }
          else{
            leapCount++;
          }
        }
      }
    }
  }
  */
  if(x>300){
    printf("Invalid number of days\n");
    exit(0);
  }
  if(mm > 0 && mm<13){
    ;
  }
  else{
    printf("Invalid date\n");
    exit(1);
  }
  if(dd >= 1 && dd <= monthLength[mm-1]){
    ;
  }
  else if(mm == 2 && dd == 29){
    if(yyyy%4 == 0){
      if(yyyy%400 == 0){
        ;
      }
      else if(yyyy%100 == 0){
        printf("Invalid date\n");
        exit(1);
      }
      else{
        ;
      }
    }
    else{
      printf("Invalid date\n");
      exit(1);
    }
  }
  else{
    printf("Invalid date\n");
    exit(1);
  }
  if(yyyy>=0){
    ;
  }
  else{
    printf("Invalid date\n");
    exit(1);
  }
  /*Leap year check*/
  if(yyyy%4 == 0){
    if(yyyy%400 == 0){
      leapyear = TRUE;
    }
    else if(yyyy%100 == 0){
      leapyear = FALSE;
    }
    else{
      leapyear = TRUE;
    }
  }
  else{
    leapyear = FALSE;
  }
  if(leapyear == TRUE){
    monthLength[1] = 29;
  }
  while(x>0){
    while(dd<=monthLength[mm-1] && x>0){
      dd++;
      x--;
    }
    if(x>0){
      dd = 1;
      mm += 1;
      if(mm>12){
        dd = 1;
        mm = 1;
        yyyy++;
        leapyear = FALSE;
        if(yyyy%4 == 0){
          if(yyyy%400 == 0){
            leapyear = TRUE;
          }
          else if(yyyy%100 == 0){
            leapyear = FALSE;
          }
          else{
            leapyear = TRUE;
          }
        }
        else{
          leapyear = FALSE;
        }
        if(leapyear == TRUE){
          monthLength[1] = 29;
        }
        else{
          monthLength[1] = 28;
        }
      }
    }
  }

  printf("%02d %02d %04d\n",dd,mm,yyyy);

  return 0;
}
