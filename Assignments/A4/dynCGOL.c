#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgol.h"

int main(int argc, char *argv[]){
  FILE *fp;
  char file[MAXSIZE];
  char startQuestion[MAXSIZE];
  char continueQuestion[MAXSIZE];
  int i, j, z;
  int numTics;
  int again = TRUE;
  int equalCount = 0;
  int ticCount = 0;
  int neighbourCount = 0;
  int repeatQuestion = TRUE;
  int continueTics = 0;
  int rows, cols;
  int test = 0;
  int elementCount = 0;
  i = 0;
  j = 0;
  z = 0;

  if((argc == 5)){

    /* Assigning command line arguments to variables*/
    numTics = atoi(argv[2]);
    if(numTics<0){
      printf("Error - Invalid number of tics (tics must be a positive integer)\n");
      exit(3);
    }
    rows = atoi(argv[3]);
    if(rows<1){
      printf("Error - Invalid number of rows (rows must be a positive integer)\n");
      exit(3);
    }
    cols = atoi(argv[4]);
    if(cols<1){
      printf("Error - Invalid number of columns (columns must be a positive integer)\n");
      exit(3);
    }
    continueTics = numTics;

    /*Initializing arrays with command line arguments*/
    char grid[rows][cols];
    char newGrid[rows][cols];
    int digit[rows][cols];


    /*Read file to 2D array*/
    strcpy(file,argv[1]);

    if((fp = fopen(file,"r")) != NULL){

      while((fscanf(fp,"%d",&test))!= EOF){
        elementCount++;
      }

      if(elementCount == rows*cols){
        /*Array is the correct Dimensions*/;
      }
      else{
        printf("Error - Invalid 2D Array Provided (Array must be 20X40)\n");
        exit(6);
      }
      fclose(fp);
      fp = fopen(file,"r"); /*Already know that file is not equal to NULL since opened before on success*/

      for(i = 0; i<rows; i++){
        for(j = 0; j<cols; j++){
          fscanf(fp,"%d",&digit[i][j]);
        }
      }
    }
    else{
      printf("Error - Invalid File\n");
      exit(1);
    }
    fclose(fp);

    /*print grid*/
    system("clear");
    system("sleep 0.25");
    printf(" ");
    for(z=0;z<cols;z++){
      printf("-");
    }

    for(i=0; i<rows; i++){
      printf("\n");
      printf("|");
      for(j=0; j<cols; j++){

        if(digit[i][j] == 0){
          grid[i][j] = ' ';
        }
        else if(digit[i][j] == 1){
          grid[i][j] = 'x';
        }
        printf("%c",grid[i][j]);
        if(j+1 == cols){
          printf("|");
        }
      }
    }
    printf("\n");
    printf(" ");
    for(z=0;z<cols;z++){
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

        for(i = 0; i<rows; i++){
          for(j = 0; j<cols; j++){
            /*Checking number of live neighbours*/
            if((grid[i-1][j-1] == 'x')&&(i>0)&&(j>0)){
              neighbourCount++;
            }
            if((grid[i-1][j] == 'x')&&(i>0)){
              neighbourCount++;
            }
            if((grid[i-1][j+1] == 'x')&&(i>0)&&(j<cols-1)){
              neighbourCount++;
            }
            if((grid[i][j-1] == 'x')&&(j>0)){
              neighbourCount++;
            }
            if((grid[i][j+1] == 'x')&&(j<cols-1)){
              neighbourCount++;
            }
            if((grid[i+1][j-1] == 'x')&&(i<rows-1)&&(j>0)){
              neighbourCount++;
            }
            if((grid[i+1][j] == 'x')&&(i<rows-1)){
              neighbourCount++;
            }
            if((grid[i+1][j+1] == 'x')&&(i<rows-1)&&(j<cols-1)){
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
        for(i=0; i<rows; i++){
          for(j=0; j<cols; j++){
            if(grid[i][j] == newGrid[i][j]){
              equalCount++;
            }
          }
        }
        if((rows*cols) == equalCount){
          exit(5);
        }

        /*Apply changes to grid*/
        for(i=0; i<rows; i++){
          for(j=0; j<cols; j++){
            grid[i][j] = newGrid[i][j];
          }
        }

        /*print grid*/
        system("sleep 0.25");
        system("clear");
        printf(" ");
        for(z=0;z<cols;z++){
          printf("-");
        }

        for(i=0; i<rows; i++){
          printf("\n");
          printf("|");
          for(j=0; j<cols; j++){
            printf("%c",grid[i][j]);
            if(j+1 == cols){
              printf("|");
            }
          }
        }
        printf("\n");
        printf(" ");
        for(z=0;z<cols;z++){
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
  }
  else{
    printf("Error - Invalid number of arguments provided\n");
    printf("Usage: ./dynCGOL nameFile.seed ticks rows col\n");
    exit(2);
  }
  return(0);
}
