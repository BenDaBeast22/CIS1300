#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 200
#define UNRANKED -2
#define TRUE 0
#define FALSE -1
#include "babies.h"
int main(){

  FILE *fp1;
  FILE *fp2;

  struct pNames decade1;
  struct pNames decade2;

  char decade[MAXSIZE];
  char decadeQuestion1[MAXSIZE];
  char decadeQuestion2[MAXSIZE];
  char text[MAXSIZE];
  char decision1[MAXSIZE];
  char rankNumber[MAXSIZE];
  char displayRank[MAXSIZE];
  char displaySearch[MAXSIZE];
  char nameSearch[MAXSIZE];
  char anotherQuestion[MAXSIZE];
  char anotherYear[MAXSIZE];
  char femaleCommonTen[MAXSIZE];
  char maleCommonTen[MAXSIZE];

  int rank = 0;
  int year1 = 0;
  int year2 = 0;
  int repeat = TRUE;
  int repeat2 = TRUE;
  int repeatQuestion = 0;
  int maleRank1 = 0;
  int maleRank2 = 0;
  int femaleRank1 = 0;
  int femaleRank2 = 0;

  int maleSearch1 = -2;
  int maleSearch2 = -2;
  int femaleSearch1 = -2;
  int femaleSearch2 = -2;

  int i = 0;
  int j = 0;
  int femaleTen = 0;
  int maleTen = 0;

  int findData1(char *decadeQuestion1){
    decade1.year = atoi(decadeQuestion1);
    strcat(decadeQuestion1,"Names.txt");
    if((fp1 = fopen(decadeQuestion1,"r"))!= NULL){
      i = 0;
      while((fgets(text,ROWS,fp1))!= NULL){
        removeCommas(text);
        sscanf(text,"%d %s %d %s %d", &decade1.rank[i], decade1.maleName[i], &decade1.maleNumber[i], decade1.femaleName[i], &decade1.femaleNumber[i]);
        i++;
      }
    }
    else{
      decade1.year = atoi(decadeQuestion1);
      printf("Error can not open %dNames.txt\n",decade1.year);
      return(-1);
    }
    fclose(fp1);
    return(0);

  }
  int findData2(char *decadeQuestion2){
    decade2.year = atoi(decadeQuestion2);
    strcat(decadeQuestion2,"Names.txt");
    if((fp2 = fopen(decadeQuestion2,"r"))!= NULL){
      i = 0;
      while((fgets(text,ROWS,fp2))!= NULL){
        removeCommas(text);
        sscanf(text,"%d %s %d %s %d", &decade2.rank[i], decade2.maleName[i], &decade2.maleNumber[i], decade2.femaleName[i], &decade2.femaleNumber[i]);
        i++;
      }
    }
    else{
      decade2.year = atoi(decadeQuestion2);
      printf("Error can not open %dNames.txt\n",decade2.year);
      return(-1);
    }
    fclose(fp2);
    return(0);

  }
  while(repeat == TRUE){
    repeat2 = TRUE;
    repeatQuestion = TRUE;
    while(repeatQuestion == TRUE){
      printf("What 2 decades do you want to look at? [1880 to 2010]:");
      fgets(decade,MAXSIZE,stdin);
      sscanf(decade,"%s %s",decadeQuestion1,decadeQuestion2);
      chop(decadeQuestion1);
      chop(decadeQuestion2);
      year1 = atoi(decadeQuestion1);
      year2 = atoi(decadeQuestion2);
      if((year1 == 1880||year1 == 1890||year1 == 1900||year1 == 1910||year1 == 1920||year1 == 1930 ||year1 == 1940 ||year1 == 1950 ||year1 == 1960 ||year1 == 1970 ||year1 == 1980 ||year1 == 1990 ||year1 == 2000 ||year1 == 2010)&&(year2 == 1880||year2 == 1890||year2 == 1900||year2 == 1910||year2 == 1920||year2 == 1930 ||year2 == 1940 ||year2 == 1950 ||year2 == 1960 ||year2 == 1970 ||year2 == 1980 ||year2 == 1990 ||year2 == 2000 ||year2 == 2010)&&(year1 != year2)){
        findData1(decadeQuestion1);
        findData2(decadeQuestion2);
        repeatQuestion = FALSE;
      }
      else{
        printf("Acceptable decades are 1880, 1890, 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, or 2010, seperated by at least one space. No other numbers are acceptable. You must enter 2 acceptable decades seperated by at least one space.\n");
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
            printf("Rank %d: %d: Male: %s (%d)\n",rank,decade1.year,decade1.maleName[rank-1],decade1.maleNumber[rank-1]);
            printf("        %d: Male: %s (%d)\n",decade2.year,decade2.maleName[rank-1],decade2.maleNumber[rank-1]);
            repeatQuestion = FALSE;
          }
          else if((strcmp(displayRank,"1"))==0){
            printf("Rank %d: %d: Female: %s (%d)\n",rank,decade1.year,decade1.femaleName[rank-1],decade1.femaleNumber[rank-1]);
            printf("        %d: Female: %s (%d)\n",decade2.year,decade2.femaleName[rank-1],decade2.femaleNumber[rank-1]);
            repeatQuestion = FALSE;
          }
          else if((strcmp(displayRank,"2"))==0){
            printf("Rank %d: %d: Male: %s (%d) and Female: %s (%d)\n",rank,decade1.year,decade1.maleName[rank-1],decade1.maleNumber[rank-1],decade1.femaleName[rank-1],decade1.femaleNumber[rank-1]);
            printf("        %d: Male: %s (%d) and Female: %s (%d)\n",decade2.year,decade2.maleName[rank-1],decade2.maleNumber[rank-1],decade2.femaleName[rank-1],decade2.femaleNumber[rank-1]);
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

        maleSearch1 = UNRANKED;
        maleSearch2 = UNRANKED;
        femaleSearch1 = UNRANKED;
        femaleSearch2 = UNRANKED;
        for(i=0;i<MAXSIZE;i++){
          if((strcmp(nameSearch,decade1.maleName[i]))==0){
            maleSearch1 = i;
            maleRank1 = i+1;
          }
          if((strcmp(nameSearch,decade1.femaleName[i]))==0){
            femaleSearch1 = i;
            femaleRank1 = i+1;
          }
          if((strcmp(nameSearch,decade2.maleName[i]))==0){
            maleSearch2 = i;
            maleRank2 = i+1;
          }
          if((strcmp(nameSearch,decade2.femaleName[i]))==0){
            femaleSearch2 = i;
            femaleRank2 = i+1;
          }

        }
        repeatQuestion = TRUE;
        while(repeatQuestion == TRUE){
          printf("Do you wish to search male (0), female (1), or both (2) name? [0-2]:");
          fgets(displaySearch,MAXSIZE,stdin);
          chop(displaySearch);

          if((strcmp(displaySearch,"0")) == 0){
            if((maleSearch1 == UNRANKED)&&(maleSearch2 == UNRANKED)){
              printf("In %d, the male name %s is not ranked and\n",decade1.year,nameSearch);
              printf("In %d, the male name %s is not ranked\n",decade2.year,nameSearch);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 == UNRANKED)&&(maleSearch2 != UNRANKED)){
              printf("In %d, the male name %s is not ranked and\n",decade1.year,nameSearch);
              printf("In %d, the male name %s is ranked %d with a count of %d\n",decade2.year,decade2.maleName[maleSearch2],maleRank2,decade2.maleNumber[maleSearch2]);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 != UNRANKED)&&(maleSearch2 == UNRANKED)){
                printf("In %d, the male name %s is ranked %d with a count of %d and\n",decade1.year,decade1.maleName[maleSearch1],maleRank1,decade1.maleNumber[maleSearch1]);
                printf("In %d, the male name %s is not ranked\n",decade2.year,nameSearch);
                repeatQuestion = FALSE;
            }
            else{
              printf("In %d, the male name %s is ranked %d with a count of %d and\n",decade1.year,decade1.maleName[maleSearch1],maleRank1,decade1.maleNumber[maleSearch1]);
              printf("In %d, the male name %s is ranked %d with a count of %d\n",decade2.year,decade2.maleName[maleSearch2],maleRank2,decade2.maleNumber[maleSearch2]);
              repeatQuestion = FALSE;
            }
          }
          else if((strcmp(displaySearch,"1")) == 0){
            if((femaleSearch1 == UNRANKED)&&(femaleSearch2 == UNRANKED)){
              printf("In %d, the female name %s is not ranked and\n",decade1.year,nameSearch);
              printf("In %d, the female name %s is not ranked\n",decade2.year,nameSearch);
              repeatQuestion = FALSE;
            }
            else if((femaleSearch1 == UNRANKED)&&(femaleSearch2 != UNRANKED)){
              printf("In %d, the female name %s is not ranked and\n",decade1.year,nameSearch);
              printf("In %d, the female name %s is ranked %d with a count of %d\n",decade2.year,decade2.femaleName[femaleSearch2],femaleRank2,decade2.femaleNumber[femaleSearch2]);
              repeatQuestion = FALSE;
            }
            else if((femaleSearch1 != UNRANKED)&&(femaleSearch2 == UNRANKED)){
                printf("In %d, the female name %s is ranked %d with a count of %d and\n",decade1.year,decade1.femaleName[femaleSearch1],femaleRank1,decade1.femaleNumber[femaleSearch1]);
                printf("In %d, the female name %s is not ranked\n",decade2.year,nameSearch);
                repeatQuestion = FALSE;
            }
            else{
              printf("In %d, the female name %s is ranked %d with a count of %d and\n",decade1.year,decade1.femaleName[femaleSearch1],femaleRank1,decade1.femaleNumber[femaleSearch1]);
              printf("In %d, the female name %s is ranked %d with a count of %d\n",decade2.year,decade2.femaleName[femaleSearch2],femaleRank2,decade2.femaleNumber[femaleSearch2]);
              repeatQuestion = FALSE;
            }
          }
          else if((strcmp(displaySearch,"2")) == 0){
            if((maleSearch1 == UNRANKED)&&(maleSearch2 == UNRANKED)&&(femaleSearch1 == UNRANKED)&&(femaleSearch2 == UNRANKED)){
              printf("In %d, the female name %s is not ranked and the male name %s is not ranked\n",decade1.year,nameSearch,nameSearch);
              printf("And in %d, the female name %s is not ranked and the male name %s is not ranked\n",decade2.year,nameSearch,nameSearch);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 != UNRANKED)&&(maleSearch2 == UNRANKED)&&(femaleSearch1 == UNRANKED)&&(femaleSearch2 == UNRANKED)){
              printf("In %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d\n",decade1.year,nameSearch,nameSearch,maleRank1,decade1.maleNumber[maleSearch1]);
              printf("And in %d, the female name %s is not ranked and the male name %s is not ranked\n",decade2.year,nameSearch,nameSearch);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 == UNRANKED)&&(maleSearch2 != UNRANKED)&&(femaleSearch1 == UNRANKED)&&(femaleSearch2 == UNRANKED)){
              printf("In %d, the female name %s is not ranked and the male name %s is not ranked\n",decade1.year,nameSearch,nameSearch);
              printf("And in %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d\n",decade2.year,nameSearch,nameSearch,maleRank2,decade2.maleNumber[maleSearch2]);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 == UNRANKED)&&(maleSearch2 == UNRANKED)&&(femaleSearch1 != UNRANKED)&&(femaleSearch2 == UNRANKED)){
              printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked\n",decade1.year,nameSearch,femaleRank1,decade1.femaleNumber[femaleSearch1],nameSearch);
              printf("And in %d, the female name %s is not ranked and the male name %s is not ranked\n",decade2.year,nameSearch,nameSearch);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 == UNRANKED)&&(maleSearch2 == UNRANKED)&&(femaleSearch1 == UNRANKED)&&(femaleSearch2 != UNRANKED)){
              printf("In %d, the female name %s is not ranked and the male name %s is not ranked\n",decade1.year,nameSearch,nameSearch);
              printf("And in %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked\n",decade2.year,nameSearch,femaleRank2,decade2.femaleNumber[femaleSearch2],nameSearch);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 != UNRANKED)&&(maleSearch2 != UNRANKED)&&(femaleSearch1 == UNRANKED)&&(femaleSearch2 == UNRANKED)){
              printf("In %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d\n",decade1.year,nameSearch,nameSearch,maleRank1,decade1.maleNumber[maleSearch1]);
              printf("And in %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d\n",decade2.year,nameSearch,nameSearch,maleRank2,decade2.maleNumber[maleSearch2]);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 == UNRANKED)&&(maleSearch2 != UNRANKED)&&(femaleSearch1 != UNRANKED)&&(femaleSearch2 == UNRANKED)){
              printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked\n",decade1.year,nameSearch,femaleRank1,decade1.femaleNumber[femaleSearch1],nameSearch);
              printf("And in %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d\n",decade2.year,nameSearch,nameSearch,maleRank2,decade2.maleNumber[maleSearch2]);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 == UNRANKED)&&(maleSearch2 == UNRANKED)&&(femaleSearch1 != UNRANKED)&&(femaleSearch2 != UNRANKED)){
              printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked\n",decade1.year,nameSearch,femaleRank1,decade1.femaleNumber[femaleSearch1],nameSearch);
              printf("And in %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked\n",decade2.year,nameSearch,femaleRank2,decade2.femaleNumber[femaleSearch2],nameSearch);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 != UNRANKED)&&(maleSearch2 == UNRANKED)&&(femaleSearch1 != UNRANKED)&&(femaleSearch2 == UNRANKED)){
              printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d\n",decade1.year,nameSearch,femaleRank1,decade1.femaleNumber[femaleSearch1],nameSearch,maleRank1,decade1.maleNumber[maleSearch1]);
              printf("And in %d, the female name %s is not ranked and the male name %s is not ranked\n",decade2.year,nameSearch,nameSearch);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 == UNRANKED)&&(maleSearch2 != UNRANKED)&&(femaleSearch1 == UNRANKED)&&(femaleSearch2 != UNRANKED)){
              printf("In %d, the female name %s is not ranked and the male name %s is not ranked\n",decade1.year,nameSearch,nameSearch);
              printf("And in %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d\n",decade2.year,nameSearch,femaleRank2,decade2.femaleNumber[femaleSearch2],nameSearch,maleRank2,decade2.maleNumber[maleSearch2]);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 != UNRANKED)&&(maleSearch2 != UNRANKED)&&(femaleSearch1 != UNRANKED)&&(femaleSearch2 == UNRANKED)){
              printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d\n",decade1.year,nameSearch,femaleRank1,decade1.femaleNumber[femaleSearch1],nameSearch,maleRank1,decade1.maleNumber[maleSearch1]);
              printf("And in %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d\n",decade2.year,nameSearch,nameSearch,maleRank2,decade2.maleNumber[maleSearch2]);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 == UNRANKED)&&(maleSearch2 != UNRANKED)&&(femaleSearch1 != UNRANKED)&&(femaleSearch2 != UNRANKED)){
              printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked\n",decade1.year,nameSearch,femaleRank1,decade1.femaleNumber[femaleSearch1],nameSearch);
              printf("And in %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d\n",decade2.year,nameSearch,femaleRank2,decade2.femaleNumber[femaleSearch2],nameSearch,maleRank2,decade2.maleNumber[maleSearch2]);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 != UNRANKED)&&(maleSearch2 != UNRANKED)&&(femaleSearch1 != UNRANKED)&&(femaleSearch2 != UNRANKED)){
              printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d\n",decade1.year,nameSearch,femaleRank1,decade1.femaleNumber[femaleSearch1],nameSearch,maleRank1,decade1.maleNumber[maleSearch1]);
              printf("And in %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d\n",decade2.year,nameSearch,femaleRank2,decade2.femaleNumber[femaleSearch2],nameSearch,maleRank2,decade2.maleNumber[maleSearch2]);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 != UNRANKED)&&(maleSearch2 == UNRANKED)&&(femaleSearch1 == UNRANKED)&&(femaleSearch2 != UNRANKED)){
              printf("In %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d\n",decade1.year,nameSearch,nameSearch,maleRank1,decade1.maleNumber[maleSearch1]);
              printf("And in %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked\n",decade2.year,nameSearch,femaleRank2,decade2.femaleNumber[femaleSearch2],nameSearch);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 != UNRANKED)&&(maleSearch2 == UNRANKED)&&(femaleSearch1 != UNRANKED)&&(femaleSearch2 != UNRANKED)){
              printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d\n",decade1.year,nameSearch,femaleRank1,decade1.femaleNumber[femaleSearch1],nameSearch,maleRank1,decade1.maleNumber[maleSearch1]);
              printf("And in %d, the female name %s is ranked %d with a count of %d and the male name %s is not ranked\n",decade2.year,nameSearch,femaleRank2,decade2.femaleNumber[femaleSearch2],nameSearch);
              repeatQuestion = FALSE;
            }
            else if((maleSearch1 != UNRANKED)&&(maleSearch2 != UNRANKED)&&(femaleSearch1 == UNRANKED)&&(femaleSearch2 != UNRANKED)){
              printf("In %d, the female name %s is ranked %d with a count of %d and the male name %s is ranked %d with a count of %d\n",decade1.year,nameSearch,femaleRank1,decade1.femaleNumber[femaleSearch1],nameSearch,maleRank1,decade1.maleNumber[maleSearch1]);
              printf("And in %d, the female name %s is not ranked and the male name %s is ranked %d with a count of %d\n",decade2.year,nameSearch,nameSearch,maleRank2,decade2.maleNumber[maleSearch2]);
              repeatQuestion = FALSE;
            }

      }
          else{
            printf("Only the numbers 0,1, or 2 are acceptable.\n");
          }
        }
      }
      else if((strcmp(decision1,"top"))==0){
        for(i=0;i<10;i++){
          for(j=0;j<10;j++){
            if((strcmp(decade1.femaleName[i],decade2.femaleName[j]) == 0)){
              strcat(femaleCommonTen,decade1.femaleName[i]);
              strcat(femaleCommonTen,", ");

            }
            if((strcmp(decade1.maleName[i],decade2.maleName[j]) == 0)){
              strcat(maleCommonTen,decade1.maleName[i]);
              strcat(maleCommonTen,", ");
            }
          }
        }
        femaleTen = strlen(femaleCommonTen);
        maleTen = strlen(maleCommonTen);
        femaleCommonTen[femaleTen-2] = '\0';
        maleCommonTen[maleTen-2] = '\0';
        printf("Male names that appear in both %d and %d Top Tens: %s\n",decade1.year,decade2.year,maleCommonTen);
        printf("Female names that appear in both %d and %d Top Tens: %s\n",decade1.year,decade2.year,femaleCommonTen);
        femaleCommonTen[0] = '\0';
        maleCommonTen[0] = '\0';
      }
      repeatQuestion = TRUE;
      while(repeatQuestion == TRUE){
        printf("Do you want to ask another question about %d and %d? [Y or N]:",decade1.year,decade2.year);
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
          printf("Would you like to select other decades? [Y or N]:");
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
  printf("Thank you for using babiesQuery\n");
  return(0);
}
