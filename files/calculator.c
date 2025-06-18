/*
  calculator app that performs addition,substraction, multiplication, division
*/

#include <stdio.h>
#include <stdlib.h>

double calcuate(double a, double b, char op);


int main(void){
  double a;
  char op;
  double b;

  printf("First Number: ");
  scanf("%lf", &a);

  printf("Operator (+, -, * or /): ");
  scanf(" %c", &op);

  printf("Second Number: ");
  scanf("%lf", &b);

  printf("Result is: %lf", calcuate(a, b, op));
}

double calcuate(double a , double b , char op){
  double res;
  
  switch(op){
    case '+':{
      res = a + b;
      break;
    }
    case '-':{
      res = a - b;
      break;
    }
    case '*':{
      res = a * b;
      break;
    }
    case '/':{
      res = a / b;
      break;
    }
  }

  return res;
}
