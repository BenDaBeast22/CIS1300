#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define YEAR 365
#define FALSE 0
#define TRUE 1
/*I used the code to find the current date from the website techiedelight.com/print-current-date-and-time-in-c*/
/*Comments will be used to identify the code form the website*/
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
  int i;
  int leapCount;

  int dayofyear[12] = {1,32,60,91,121,152,182,213,244,274,305,335};
  int monthLength[12] = {31, 28 ,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  char ddStr1[3];
  char mmStr1[3];
  char yyyyStr1[5];
  char ddStr2[3];
  char mmStr2[3];
  char yyyyStr2[5];

  /*I got this code from the website techiedelight.com/print-current-date-and-time-in-c/*/
  time_t now;
  time(&now);
  struct tm *local = localtime(&now);

  include = FALSE;

  if(argc==4){
    if(strcmp("include", argv[3])==0){
      include = TRUE;
    }
  }

  if(argc<3){
    printf("Usage ./daysApart dd1-mm1-yyyy1 dd2-mm2-yyyy2\n");
    exit(1);
  }
  else{
    if(strcmp("today", argv[1])==0){
      /*I got this code from the website techiedelight.com/print-current-date-and-time-in-c/*/
      dd1 = local->tm_mday;
      mm1 = local->tm_mon +1;
      yyyy1 = local->tm_year +1900;
    }
    else{
      ddStr1[0] = argv[1][0];
      ddStr1[1] = argv[1][1];
      ddStr1[2] = '\0';

      mmStr1[0] = argv[1][3];
      mmStr1[1] = argv[1][4];
      mmStr1[2] = '\0';

      yyyyStr1[0] = argv[1][6];
      yyyyStr1[1] = argv[1][7];
      yyyyStr1[2] = argv[1][8];
      yyyyStr1[3] = argv[1][9];
      yyyyStr1[4] = '\0';

      dd1 = atoi(ddStr1);
      mm1 = atoi(mmStr1);
      yyyy1 = atoi(yyyyStr1);
    }
    if(strcmp("today", argv[2])==0){
      /*I got this code from the website techiedelight.com/print-current-date-and-time-in-c/*/
      dd2 = local->tm_mday;
      mm2 = local->tm_mon +1;
      yyyy2 = local->tm_year +1900;
    }
    else{
      ddStr2[0] = argv[2][0];
      ddStr2[1] = argv[2][1];
      ddStr2[2] = '\0';

      mmStr2[0] = argv[2][3];
      mmStr2[1] = argv[2][4];
      mmStr2[2] = '\0';

      yyyyStr2[0] = argv[2][6];
      yyyyStr2[1] = argv[2][7];
      yyyyStr2[2] = argv[2][8];
      yyyyStr2[3] = argv[2][9];
      yyyyStr2[4] = '\0';

      dd2 = atoi(ddStr2);
      mm2 = atoi(mmStr2);
      yyyy2 = atoi(yyyyStr2);
    }
  }
  yeardiff = yyyy2-yyyy1;
  leapCount = 0;
  /*Checks the leap year on start date*/
  if(yeardiff>=0){
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
  /*Checks for leap year for every year between start and end date and adds an extra day for every leap year*/
  if(yeardiff>=0) {
    for(i = yyyy1+1;i<=yyyy2-1;i++){
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
  /*Checks for leap year on end date*/
  if(yeardiff>0){
    if((mm1<=2)&&(mm2>2)){
      for(i = yyyy2;i<yyyy2+1;i++){
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
