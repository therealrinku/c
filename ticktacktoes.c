// let's build a tick tack toes

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void movePlayer(void);
void moveComputer(void);
void checkWinner(void);
bool isBoardFilled(void);
int checkIfSomeoneWonTheGame(void);
void printBoard(void);
char *getBoardIndex(int pos);

struct Point {
  int x;
  int y;
};

static const char PLAYER = 'X';
static const char COMPUTER = 'P';

char board[3][3] = {{'0', '0', '0'}, {'0', '0', '0'}, {'0', '0', '0'}};

int main(void) {
  printBoard();
  movePlayer();
  int winner = checkIfSomeoneWonTheGame();
  if (winner != -1) {
    return 0;
  }
  moveComputer();
  int winnerA = checkIfSomeoneWonTheGame();
  
  if (winnerA != -1) {
    return 0;
  }
  printBoard();

  if (isBoardFilled()) {
    printf("Game Over, It's a fucking tie.");
  } else {
    printf("Another Round\n");
    main();
  }

  return 0;
};

void printBoard() {
  for (int i = 0; i < 3; i++) {
    printf("-- %c -- %c -- %c --\n", board[i][0], board[i][1], board[i][2]);
    printf("\n");
  }
}

char *getBoardIndex(int pos) {
  if (pos == 1) {
    return "00";
  } else if (pos == 2) {
    return "01";
  } else if (pos == 3) {
    return "02";
  } else if (pos == 4) {
    return "10";
  } else if (pos == 5) {
    return "11";
  } else if (pos == 6) {
    return "12";
  } else if (pos == 7) {
    return "20";
  } else if (pos == 8) {
    return "21";
  } else if (pos == 9) {
    return "22";
  } else {
    return "Invalid";
  }
};

void movePlayer() {
  int pos;

  printf("Enter your next position(1-9):");
  scanf("%d", &pos);

  char *posXY = getBoardIndex(pos);

  if (strcmp(posXY, "Invalid") == 0) {
    printf("Invalid Position, Retry Again!");
    movePlayer();
  }

  int posX = posXY[0] - '0';
  int posY = posXY[1] - '0';

  if (board[posX][posY] != '0') {
    printf("Invalid Position, Retry Again!");
    movePlayer();
  } else {
    board[posX][posY] = PLAYER;
  }
}

void moveComputer() {
  // Seed the random number generator
   time_t t;
   srand(time(&t));

  int pos = rand() % 9 + 1;

  char *posXY = getBoardIndex(pos);

  int posX = posXY[0] - '0';
  int posY = posXY[1] - '0';

  if (board[posX][posY] != '0') {
    moveComputer();
  } else {
    board[posX][posY] = COMPUTER;
  }
}

bool isBoardFilled(void) {
  int emptySpaces = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == '0') {
        emptySpaces++;
      }
    }
  }

  return emptySpaces == 0;
}

int checkIfSomeoneWonTheGame(void) {
  char winner;

  // check rows and columns
  for (int i = 0; i < 3; i++) {
    // rows
    if (board[i][0] != '0' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      winner = board[i][0];
      break;
    }
    // cols
    else if (board[0][i] != '0' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      winner = board[0][i];
      break;
    }
  }

  // check diagonals
  if (board[0][0] != '0' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    winner = board[0][0];
  } else if (board[0][2] != '0' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    winner = board[0][2];
  }

  if (winner == PLAYER) {
    printf("Game Over! You have won it bruh.");
    return 0;
  } else if (winner == COMPUTER) {
    printf("Game Over! You're a loser.");
    return 1;
  }

  return -1;
}
