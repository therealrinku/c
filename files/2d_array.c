/*
  program to allocate 2d array based on user given rows and cols
  then add values to those rols and cols at valid position based on user input
  when user clicks q quit and logs the final array
  when user clicks i logs the final array
  2024-05-25
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int** allocate2dArray(int row, int col);
void deallocate2dArray(int** array, int row);
void print2dArray(int** array, int row, int col);
void addValue(int** array,int row, int col, char* pos, int value);

int main(void){
  int row;
  int col;

  printf("Type number of rows you want:");
  scanf("%i", &row);


  printf("Type number of columns you want:");
  scanf("%i", &col);

  int **arr = allocate2dArray(row, col);

  while(true){
    char cmd[3];
    printf("Enter row and col position 0 Indexed>, for eg(01), q to quit, i to print array, max 2 character command:");
    scanf("%s", cmd);

    if(strlen(cmd) > 2){
      printf("Invalid command size, max len 2\n");
      continue;
    }

    if(strcmp(cmd, "q") == 0){
      printf("Final result");
      print2dArray(arr, row, col);
      deallocate2dArray(arr, row);
      break;
    }

    if(strcmp(cmd, "i") == 0){
      print2dArray(arr, row, col);
      continue;
    }

    int value;
    printf("Enter value to store at %s:", cmd);
    scanf("%i", &value);

    addValue(arr,row, col, cmd, value);
  }
}

int** allocate2dArray(int row, int col){
  int **arr = (int **)malloc(row * sizeof(int *));

  for(int i=0;i<row;i++){
    arr[i] = (int *)malloc(col * sizeof(int));
  }

  return arr;
}

void deallocate2dArray(int** array, int row){
  for(int i=0;i<row;i++){
    free(array[i]);
  }

  free(array);
}

void print2dArray(int** array, int row, int col){
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
}


void addValue(int** array, int row, int col, char* pos, int value) {
    int rowIndex = pos[0] - '0';
    int colIndex = pos[1] - '0';

    if (rowIndex < 0 || rowIndex >= row || colIndex < 0 || colIndex >= col) {
        printf("Invalid position\n");
        return;
    }

    array[rowIndex][colIndex] = value;
}
