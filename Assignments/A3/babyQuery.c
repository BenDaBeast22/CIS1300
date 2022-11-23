#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 200
#define UNRANKED -2
#define TRUE 0
#define FALSE -1
#include "babies.h"
int main(){

  FILE *fp;

  struct pNames popular;
  char decade[MAXSIZE];
  char text[MAXSIZE];
  char decision1[MAXSIZE];
  char rankNumber[MAXSIZE];
  char displayRank[MAXSIZE];
  char displaySearch[MAXSIZE];
  char nameSearch[MAXSIZE];
  char anotherQuestion[MAXSIZE];
  char anotherYear[MAXSIZE];

  int rank = 0;
  int year = 0;
  int repeat = TRUE;
  int repeat2 = TRUE;
  int repeatQuestion = 0;
  int maleRank = 0;
  int femaleRank = 0;

  int maleSearch = -2;
  int femaleSearch = -2;

  int i = 0;

  int findData(char *decade){
    popular.year = atoi(decade);
    strcat(decade,"Names.txt");
    if((fp = fopen(decade,"r"))!= NULL){
      i = 0;
      while((fgets(text,ROWS,fp))!= NULL){
        removeCommas(text);
        sscanf(text,"%d %s %d %s %d", &popular.rank[i], popular.maleName[i], &popular.maleNumber[i], popular.femaleName[i], &popular.femaleNumber[i]);
        i++;
      }
    }
    else{
      popular.year = atoi(decade);
      printf("Error can not open %dNames.txt\n",popular.year);
      return(-1);
    }
    fclose(fp);
    return(0);

  }
  while(repeat == TRUE){
    repeat2 = TRUE;
    repeatQuestion = TRUE;
    while(repeatQuestion == TRUE){
      printf("What decade do you want to look at? [1880 to 2010]:");
      fgets(decade,MAXSIZE,stdin);
      chop(decade);
      year = atoi(decade);
      if(year == 1880||year == 1890||year == 1900||year == 1910||year == 1920||year == 1930 ||year == 1940 ||year == 1950 ||year == 1960 ||year == 1970 ||year == 1980 ||year == 1990 ||year == 2000 ||year == 2010){
        findData(decade);
        repeatQuestion = FALSE;
      }
      else{
        printf("Acceptable dates are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010. No other numbers are acceptable.\n");
      }
    }
    while(repeat2 == TRUE){
      repeatQuestion = TRUE;
      while(repeatQuestion == TRUE){
        printf("Would you like to see a rank, search for a name, or see the top 10? [rank,search,top]:");
        fgets(decision1,MAXSIZE,stdin);
        chop(decision1);
        if((strcmp(decision1,"rank")==0) || (strcmp(decision1,"search")==0) || (strcmp(decision1,"top")==0)){
          repeatQuestion = FALSE;
        }
        else{
          printf("Please type in rank, search, or top exactly as requested.\n");
        }
      }
      if((strcmp(decision1,"rank")==0)){
        repeatQuestion = TRUE;
        while(repeatQuestion == TRUE){
          printf("What rank do you wish to see? [1-200]:");
          fgets(rankNumber,MAXSIZE,stdin);
          chop(rankNumber);
          rank = atoi(rankNumber);
          if(rank>0 && rank<201){
            repeatQuestion = FALSE;
          }
          else{
            printf("Only numbers between 1 and 200 are acceptable.\n");
          }
        }
        repeatQuestion = TRUE;
        while(repeatQuestion == TRUE){
          printf("Would you like to see the male (0), female (1), or both (2) name(s)? [0-2]:");
          fgets(displayRank,MAXSIZE,stdin);
          chop(displayRank);

          if((strcmp(displayRank,"0"))==0){
            printf("Rank %d: Male: %s (%d)\n",rank,popular.maleName[rank-1],popular.maleNumber[rank-1]);
            repeatQuestion = FALSE;
          }
          else if((strcmp(displayRank,"1"))==0){
            printf("Rank %d: Female: %s (%d)\n",rank,popular.femaleName[rank-1],popular.femaleNumber[rank-1]);
            repeatQuestion = FALSE;
          }
          else if((strcmp(displayRank,"2"))==0){
            printf("Rank %d: Male: %s (%d) and Female: %s (%d)\n",rank,popular.maleName[rank-1],popular.maleNumber[rank-1],popular.femaleName[rank-1],popular.femaleNumber[rank-1]);
            repeatQuestion = FALSE;
          }
          else{
            printf("Only the numbers 0, 1, or 2 are acceptable.\n");
          }
        }
      }
      else if(strcmp(decision1,"search")==0){
        printf("What name do you want to search for? [case sensitive]:");
        fgets(nameSearch,MAXSIZE,stdin);
        chop(nameSearch);

        maleSearch = UNRANKED;
        femaleSearch = UNRANKED;
        for(i=0;i<MAXSIZE;i++){
          if((strcmp(nameSearch,popular.maleName[i]))==0){
            maleSearch = i;
            maleRank = i+1;
          }
          if((strcmp(nameSearch,popular.femaleName[i]))==0){
            femaleSearch = i;
            femaleRank = i+1;
          }
        }
        repeatQuestion = TRUE;
        while(repeatQuestion == TRUE){
          printf("Do you wish to search male (0), female (1), or both (2) name? [0-2]:");
          fgets(displaySearch,MAXSIZE,stdin);
          chop(displaySearch);

          if((strcmp(displaySearch,"0")) == 0){
            if(maleSearch == UNRANKED){
              printf("In %d, the male name %s is not ranked\n",popular.year,nameSearch);
              repeatQuestion = FALSE;
            }
            else{
              printf("In %d, the male name %s is ranked %d with a count of %d\n",popular.year,popular.maleName[maleSearch],maleRank,popular.maleNumber[maleSearch]);
              repeatQuestion = FALSE;
            }
          }
          else if((strcmp(displaySearch,"1")) == 0){
            if(femaleSearch == UNRANKED){
              printf("In %d, the female name %s is not ranked\n",popular.year,nameSearch);
              repeatQuestion = FALSE;
            }
            else{
              printf("In %d, the female name %s is ranked %d with a count of %d\n",popular.year,popular.femaleName[femaleSearch],femaleRank,popular.femaleNumber[femaleSearch]);
              repeatQuestion = FALSE;
            }
          }
          else if((strcmp(displaySearch,"2")) == 0){
            if((maleSearch == UNRANKED)&&(femaleSearch != UNRANKED)){
              printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked\n",popular.year,popular.femaleName[femaleSearch],femaleRank,popular.femaleNumber[femaleSearch],nameSearch);
              repeatQuestion = FALSE;
            }
            else if((maleSearch != UNRANKED)&&(femaleSearch == UNRANKED)){
              printf("In %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d\n",popular.year,nameSearch,nameSearch,maleRank,popular.maleNumber[maleSearch]);
              repeatQuestion = FALSE;
            }
            else if((maleSearch == UNRANKED)&&(femaleSearch == UNRANKED)){
              printf("In %d, the female name %s is not ranked and the male name %s is not ranked\n",popular.year,nameSearch,nameSearch);
              repeatQuestion = FALSE;
            }
            else if((femaleSearch != UNRANKED)&&(maleSearch != UNRANKED)){
              printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d\n",popular.year,popular.femaleName[femaleSearch],femaleRank,popular.femaleNumber[femaleSearch],nameSearch,maleRank,popular.maleNumber[maleSearch]);
              repeatQuestion = FALSE;
            }
          }
          else{
            printf("Only the numbers 0, 1, or 2 are acceptable.\n");
          }

        }

      }
      else if(strcmp(decision1,"top")==0){
        for(i = 0;i<10;i++){
          printf("%-3d   %-12s      %-8d      %-12s      %-8d\n",popular.rank[i], popular.maleName[i], popular.maleNumber[i], popular.femaleName[i], popular.femaleNumber[i]);
        }
      }
      repeatQuestion = TRUE;
      while(repeatQuestion == TRUE){
        printf("Do you want to ask another question about %d? [Y or N]:",popular.year);
        fgets(anotherQuestion,MAXSIZE,stdin);
        chop(anotherQuestion);
        if((strcmp(anotherQuestion,"Y")) == 0 || (strcmp(anotherQuestion,"y")) == 0){
          repeatQuestion = FALSE;
        }
        else if((strcmp(anotherQuestion,"N")) == 0 || (strcmp(anotherQuestion,"n")) == 0){
          repeatQuestion = FALSE;
        }
        else{
          printf("Only the single characters Y or N are acceptable.\n");
        }
      }
      if((strcmp(anotherQuestion,"Y")) == 0 || (strcmp(anotherQuestion,"y")) == 0){
        ;
      }
      else if((strcmp(anotherQuestion,"N")) == 0 || (strcmp(anotherQuestion,"n")) == 0){
        repeatQuestion = TRUE;
        while(repeatQuestion == TRUE){
          printf("Would you like to select another year? [Y or N]:");
          fgets(anotherYear,MAXSIZE,stdin);
          chop(anotherYear);
          if((strcmp(anotherYear,"Y")) == 0 || (strcmp(anotherYear,"y")) == 0){
            repeat2 = FALSE;
            repeatQuestion = FALSE;


          }
          else if((strcmp(anotherYear,"N")) == 0 || (strcmp(anotherYear,"n")) == 0){
            repeat = FALSE;
            repeat2 = FALSE;
            repeatQuestion = FALSE;
          }
          else{
            printf("Only the single characters Y or N are acceptable.\n");
          }
        }
      }

    }

  }
  printf("Thank you for using babyQuery\n");
  return(0);
}
