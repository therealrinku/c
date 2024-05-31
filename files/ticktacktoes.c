/*
  tick tac toe -- rewrite on May 31 2024
*/

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int row;
  int col;
} RowColIndex;


const char player = 'X';
const char computer = 'C';
// 'X' or 'C'; X for player and c for computer; ' ' if nobody has won yet, 'D' if draw
char winner = ' ';
char board[3][3] = {{ '0' , '0', '0' }, { '0' , '0', '0' }, { '0' , '0', '0' }};

void printBoard(void);
void movePlayer(void);
void moveComputer(void);
RowColIndex getRowAndColIndex(int pos);
// 0 if nobody won and 1 if someone won, -1 if draw
int checkIfSomeoneWon(void);
bool isBoardFilled(void);
void printWinner(void);
void reset(void);


int main(void){
  // s rand   
  srand(time(NULL));

  printf("----WELCOME to ticktacktoes----\n");

  while(winner == ' '){
    printBoard();

    movePlayer();
    int resp1 = checkIfSomeoneWon();
    if(resp1 == 1 || resp1 == -1){
      break;
    }
   
    moveComputer();
    int resp2 = checkIfSomeoneWon();
    if(resp2 == 1 || resp2 == -1){
      break;
    }
  }

  printBoard();
  printWinner();

  char resp;
  printf("Do you want to replay?, y or n:");
  scanf("%s", &resp);

  printf("\n");

  if(strcmp(&resp, "y") == 0){
    reset();
    main();
  }else{
    printf("Thanks for playing :))");
  }
  
  return 0;
}

void printBoard(void){
  printf("\n");

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      printf("%c  ", board[i][j]);
    }

    printf("\n");
  }
}

void movePlayer(void){
  printf("\n");

  int pos;
  printf("Type a position you want to make a move (1-9):");
  scanf("%i", &pos);

  RowColIndex rowAndColIndex = getRowAndColIndex(pos);

  if(board[rowAndColIndex.row][rowAndColIndex.col] != '0'){
    printf("Invalid position, it should be (1-9 and make sure it's not filled already.");
    movePlayer();
  }
  else {
   board[rowAndColIndex.row][rowAndColIndex.col] =  player;
  }
}

void moveComputer(void){

  int pos = rand() % 9 + 1;

  RowColIndex rowAndColIndex = getRowAndColIndex(pos);
  if(board[rowAndColIndex.row][rowAndColIndex.col] != '0'){
    moveComputer();
  }
  else {
   board[rowAndColIndex.row][rowAndColIndex.col] =  computer;
  }
}

RowColIndex getRowAndColIndex(int pos){
  RowColIndex point;

  if (pos > 9 || pos < 0) {
    point.row = -1;
    point.col = -1;

    return point;
  }
  

  if(pos == 1){
    point.row = 0;
    point.col = 0;
  }
  else if(pos == 2){
    point.row = 0;
    point.col = 1;
  }
  else if(pos == 3){
    point.row = 0;
    point.col = 2;
  }
  else if(pos == 4){
    point.row = 1;
    point.col = 0;
  }
  else if(pos == 5){
    point.row = 1;
    point.col = 1;
  }
  else if(pos == 6){
    point.row = 1;
    point.col = 2;
  }
  else if(pos == 7){
    point.row = 2;
    point.col = 0;
  }
  else if(pos == 8){
    point.row = 2;
    point.col = 1;
  }
  else if(pos == 9){
    point.row = 2;
    point.col = 2;
  }

  return point;
};

int checkIfSomeoneWon(void){
  // check row, check coolumn, check duiagonal
  
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      //row
      if(board[i][0]  != '0' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
        winner = board[i][0];
        return 1;
        break;
      }

      //col
      if(board[0][i]  != '0' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
        winner = board[0][i];
        return 1;
        break;
      }
    }
  }

  //check diagonAL
  if(board[0][0] != '0' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
    winner = board[0][0];
    return 1;
  }
  else if (board[0][2] != '0' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
    winner = board[0][2];
    return 1;
  }

  if(isBoardFilled() == true){
    return -1;
  }
  
  return 0;
}

bool isBoardFilled(void){
  int emptySpaces = 0;

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(board[i][j] == '0'){
        emptySpaces++;
      }
    }
  }

  return emptySpaces == 0;
}

void printWinner(void){
  if(winner == player){
    printf("YOu won!!");
  }else if(winner == computer){
    printf("You lost :(");
  }else {
    printf("Game was a tie");
  }

  printf("\n");
}

void reset(void){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      board[i][j] = '0';
    }
  }

  winner=' ';
}
