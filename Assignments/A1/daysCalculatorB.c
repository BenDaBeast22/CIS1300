#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YEAR 365
#define FALSE 0
#define TRUE 1

int main(int argc, char *argv[]){

  int dd1 = 0;
  int mm1 = 0;
  int yyyy1 = 0;
  int dd2 = 0;
  int mm2 = 0;
  int yyyy2 = 0;
  int ytod1, ytod2;
  int mtod1, mtod2;
  int daycount1, daycount2;
  int daydiff;
  int include;
  int yeardiff;
  int leapCount;
  int i;

  include = FALSE;

  int dayofyear[12] = {1,32,60,91,121,152,182,213,244,274,305,335};
  int monthLength[12] = {31, 28 ,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if(argc==8){
    if(strcmp("include", argv[7])==0){
      include = TRUE;
    }
  }

  if(argc<7){
    printf("Usage ./daysApart dd1 mm1 yyyy1 dd2 mm2 yyyy2\n");
    exit(1);
  }
  else{
    dd1 = atoi(argv[1]);
    mm1 = atoi(argv[2]);
    yyyy1 = atoi(argv[3]);
    dd2 = atoi(argv[4]);
    mm2 = atoi(argv[5]);
    yyyy2 = atoi(argv[6]);
  }
  /*Add day if in leap year range*/
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
  /*Input Error Checks*/
  if(mm1 > 0 && mm1<13){
    ;
  }
  else{
    printf("Error the first month entered is not within in the range (1-12)\n");
    exit(2);
  }
  if(mm2 >0 && mm2<13){
    ;
  }
  else{
    printf("Error the second month entered is not within in the range (1-12)\n");
    exit(2);
  }
  if(dd1 >= 1 && dd1 <= monthLength[mm1-1]){
    ;
  }
  else if(mm1 == 2 && dd1 == 29){
    if(yyyy1%4 == 0){
      if(yyyy1%400 == 0){
        ;
      }
      else if(yyyy1%100 == 0){
        printf("Error - the first date entered %d is not within the range (1-%d)\n",dd1,monthLength[mm1-1]);
        exit(2);
      }
      else{
        ;
      }
    }
    else{
      printf("Error - the first date entered %d is not within the range (1-%d)\n",dd1,monthLength[mm1-1]);
      exit(2);
    }

  }
  else{
    printf("Error - the first date entered %d is not within the range (1-%d)\n",dd1,monthLength[mm1-1]);
    exit(2);
  }
  if(dd2 >= 1 && dd2 <= monthLength[mm2-1]){
    ;
  }
  else if(mm2 ==2 && dd2 ==29){
    if(yyyy2%4 == 0){
      if(yyyy2%400 == 0){
        ;
      }
      else if(yyyy2%100 == 0){
        printf("Error - the second date entered %d is not within the range (1-%d)\n",dd2,monthLength[mm2-1]);
        exit(2);
      }
      else{
        ;
      }
    }
    else{
      printf("Error - the second date entered %d is not within the range (1-%d)\n",dd2,monthLength[mm2-1]);
      exit(2);
    }
  }
  else{
    printf("Error - the second date entered %d is not within the range (1-%d)\n",dd2,monthLength[mm2-1]);
    exit(2);
  }
  if(yyyy1>=0){
    ;
  }
  else{
    printf("Error - the first year entered %d can not be less then 0",yyyy1);
    exit(2);
  }
  if(yyyy2>=0){
    ;
  }
  else{
    printf("Error - the second year entered %d can not be less then 0",yyyy2);
    exit(2);
  }

  /*finds the differance between the 2 dates including the start date but not including the end date*/
  ytod1 = yyyy1*YEAR;
  ytod2 = yyyy2*YEAR;

  mtod1 = dayofyear[mm1-1];
  mtod2 = dayofyear[mm2-1];

  daycount1 = ytod1 + mtod1 + dd1;
  daycount2 = ytod2 + mtod2 + dd2;

  if(include == FALSE){
    daydiff = (daycount2-daycount1)+leapCount;

  }
  else if(include == TRUE){
    daydiff = (daycount2-daycount1)+leapCount+1;
  }

  if(daydiff<0){
    printf("Error - the start day can not be after the end day\n");
    exit(3);
  }

  printf("%d\n",daydiff);

  return 0;
}
