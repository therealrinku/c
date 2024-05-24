/*
  reverses given string using pointers
  2024-may-13
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void reverseInPlace(char *str);
char* reverse(char *str);

int main(void) {
  char string[] = "pussycat";
  char string1[] = "abracadabra";

  reverseInPlace(string);

  char* reversed1 = reverse(string1);

  // it should be reversed here!!
  printf("%s\n", string);

  // string1 should be same
  printf("%s\n", string1);

  // reversed1 should be reverse of string1
  printf("%s\n", reversed1);

  return 0;
}

void reverseInPlace(char *str) {
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

char* reverse(char *str){
  int size = strlen(str);
  char* resultString = malloc((size + 1) * sizeof(char)); // Allocate memory on the heap

  strcpy(resultString, str);

  reverseInPlace(resultString);
  
  return resultString;
}
