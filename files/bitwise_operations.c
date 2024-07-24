// bitwise addition of given two numbers

#include <stdio.h>

int add(int a, int b);

int main(void){
  int a;
  int b;

  printf("enter first number:");
  scanf("%i", &a);
  printf("enter second number:");
  scanf("%i", &b);

  int resp = add(a,b);
  printf("result is %d", resp);
}

int add(int a, int b){
  while(b!=0){
    //step 1: calcuate the carry with & operator
    int carry = a & b;
    //step 2: add numbers without taking carry into consideration with xor
    a = a ^ b;
    //step 3: left shift carry by 1 and store that in b
    b = carry << 1;
  }

  return a;
}
