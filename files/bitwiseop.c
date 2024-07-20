// simple bitwise operations

#include <stdio.h>

#define FEAT_1 0b1
#define FEAT_2 0b100
#define FEAT_3 0b10000

int main(void){
  int flags = FEAT_1 | FEAT_2 | FEAT_3;

  // deactivate feature 1
  flags = flags & ~FEAT_2;

  // deactivate feature 3
  flags = flags & ~FEAT_3;

  if(flags & FEAT_1){
    printf("Feature 1 is activated!\n");
  }

  if(flags & FEAT_2){
    printf("Feature 2 is activated!\n");
  }

  if(flags & FEAT_3){
    printf("Feature 3 is activated!");
  }
  
  return 0;
}
