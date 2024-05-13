/*
  reverses given string using pointers
  2024-may-13
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void reverse(char *str);

int main(void) {
  char string[] = "pussycat";

  reverse(string);

  // it should be reversed here!!
  printf("%s", string);
  
  return 0;
}

void reverse(char *str) {
  // do pointer arthimetic here
  char *end = str;

  while (*end != '\0') {
    end = end + 1;
  }

  // move back
  end--;

  char *start = str;

  while (start < end) {
    char temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
  }
}
