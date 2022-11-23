#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgol.h"

int main(int argc, char *argv[]){
  FILE *fp;
  char grid[ROWS][COLUMNS];
  char newGrid[ROWS][COLUMNS];
  char file[MAXSIZE];
  char startQuestion[MAXSIZE];
  char continueQuestion[MAXSIZE];
  int digit[ROWS][COLUMNS];
  int i, j, z;
  int numTics;
  int again = TRUE;
  int equalCount = 0;
  int ticCount = 0;
  int neighbourCount = 0;
  int repeatQuestion = TRUE;
  int continueTics = 0;
  int elementCount = 0;
  int test = 0;
  i = 0;
  j = 0;
  z = 0;

  if((argc == 2)||(argc == 3)){
    /*Read file to 2D array*/
    strcpy(file,argv[1]);
    if((fp = fopen(file,"r")) != NULL){

      while((fscanf(fp,"%d",&test))!= EOF){
        elementCount++;
      }

      if(elementCount == ROWS*COLUMNS){
        /*Array is the correct Dimensions*/;
      }
      else{
        printf("Error - Invalid 2D Array Provided (Array must be 20X40)\n");
        exit(6);
      }
      fclose(fp);
      fp = fopen(file,"r"); /*Already know that file is not equal to NULL since opened before on success*/
      for(i = 0; i<ROWS; i++){
        for(j = 0; j<COLUMNS; j++){
          fscanf(fp,"%d",&digit[i][j]);
        }
      }

    }
    else{
      printf("Error - Invalid File\n");
      exit(1);
    }
    fclose(fp);
  }
  else{
    printf("Error - Invalid Arguments Provided\n");
    printf("Usage: ./cgol nameFile.seed (ticks)\n");
    exit(2);
  }
  if(argc == 2){
    numTics = 50;
  }
  else if(argc == 3){
    numTics = atoi(argv[2]);
    if(numTics<0){
      printf("Error - Invalid Number Provided (tic must be a positive integer)\n");
      exit(2);
    }
  }
  continueTics = numTics;

  /*print grid*/
  system("clear");
  system("sleep 0.25");
  printf(" ");
  for(z=0;z<COLUMNS;z++){
    printf("-");
  }

  for(i=0; i<ROWS; i++){
    printf("\n");
    printf("|");
    for(j=0; j<COLUMNS; j++){

      if(digit[i][j] == 0){
        grid[i][j] = ' ';
      }
      else if(digit[i][j] == 1){
        grid[i][j] = 'x';
      }
      printf("%c",grid[i][j]);
      if(j+1 == COLUMNS){
        printf("|");
      }
    }
  }
  printf("\n");
  printf(" ");
  for(z=0;z<COLUMNS;z++){
    printf("-");
  }
  printf("%d\n",ticCount);

  /*Start Question*/
  repeatQuestion = TRUE;
  while(repeatQuestion == TRUE){
    printf("Start? (y or n): ");
    fgets(startQuestion,MAXSIZE,stdin);
    chop(startQuestion);

    if(strcmp(startQuestion,"y") == 0){
      repeatQuestion = FALSE;
    }
    else if(strcmp(startQuestion,"n") == 0){
      exit(4);
    }
  }
  again = TRUE;
  while(again == TRUE){

    while(numTics>0){

      /*Evaluate Cells*/

      for(i = 0; i<ROWS; i++){
        for(j = 0; j<COLUMNS; j++){
          /*Checking number of live neighbours*/
          if((grid[i-1][j-1] == 'x')&&(i>0)&&(j>0)){
            neighbourCount++;
          }
          if((grid[i-1][j] == 'x')&&(i>0)){
            neighbourCount++;
          }
          if((grid[i-1][j+1] == 'x')&&(i>0)&&(j<COLUMNS-1)){
            neighbourCount++;
          }
          if((grid[i][j-1] == 'x')&&(j>0)){
            neighbourCount++;
          }
          if((grid[i][j+1] == 'x')&&(j<COLUMNS-1)){
            neighbourCount++;
          }
          if((grid[i+1][j-1] == 'x')&&(i<ROWS-1)&&(j>0)){
            neighbourCount++;
          }
          if((grid[i+1][j] == 'x')&&(i<ROWS-1)){
            neighbourCount++;
          }
          if((grid[i+1][j+1] == 'x')&&(i<ROWS-1)&&(j<COLUMNS-1)){
            neighbourCount++;
          }
          /*Checking if cell is live whether it survives*/
          if(grid[i][j] == 'x'){

            if((neighbourCount<2)||(neighbourCount>3)){
              grid[i][j] = ' ';
              newGrid[i][j] = grid[i][j];
              grid[i][j] = 'x';
              neighbourCount = 0;
            }
            else if((neighbourCount>1) && (neighbourCount<4)){
              newGrid[i][j] = grid[i][j];
              neighbourCount = 0;
            }
            else{
              newGrid[i][j] = grid[i][j];
              neighbourCount = 0;
            }
          }
          else if(grid[i][j] == ' '){

            if(neighbourCount == 3){
              grid[i][j] = 'x';
              newGrid[i][j] = grid[i][j];
              grid[i][j] = ' ';
              neighbourCount = 0;
            }
            else{
              newGrid[i][j] = grid[i][j];
              neighbourCount = 0;
            }

          }

          else{
            printf("Error invalid seed\n");
            exit(3);
          }
        }
      }

      /*Check if grids are the same and terminate program if this is the case*/
      equalCount = 0;
      for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
          if(grid[i][j] == newGrid[i][j]){
            equalCount++;
          }
        }
      }
      if((ROWS*COLUMNS) == equalCount){
        exit(5);
      }

      /*Apply changes to grid*/
      for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
          grid[i][j] = newGrid[i][j];
        }
      }

      /*print grid*/
      system("sleep 0.25");
      system("clear");
      printf(" ");
      for(z=0;z<COLUMNS;z++){
        printf("-");
      }

      for(i=0; i<ROWS; i++){
        printf("\n");
        printf("|");
        for(j=0; j<COLUMNS; j++){
          printf("%c",grid[i][j]);
          if(j+1 == COLUMNS){
            printf("|");
          }
        }
      }
      printf("\n");
      printf(" ");
      for(z=0;z<COLUMNS;z++){
        printf("-");
      }
      numTics--;
      ticCount++;
      printf("%d\n",ticCount);
    }
    repeatQuestion = TRUE;
    while(repeatQuestion == TRUE){
      printf("Continue? (y or n): ");
      fgets(continueQuestion,MAXSIZE,stdin);
      chop(continueQuestion);

      if(strcmp(continueQuestion,"y") == 0){
        repeatQuestion = FALSE;
        numTics = continueTics;
      }
      else if(strcmp(continueQuestion,"n") == 0){
        repeatQuestion = FALSE;
        again = FALSE;
      }
    }
  }
  return(0);
}
