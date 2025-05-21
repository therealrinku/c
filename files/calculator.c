/*
  calculator app that performs addition,substraction, multiplication and division
*/

#include <stdio.h>
#include <stdlib.h>

double calcuate(double a, double b, char op);


int main(void){
  double a;
  char op;
  double b;
  
  //char mask1 = "b7258-7d495";
  //char mask2 = "05579-ade39";
  //char mask3 = "b3f09-87e61";
  //char mask4 = "a6584-74e6f";
  //char mask5 = "c61bc-e953e";
  //char mask6 = "bafcc-9373c";
  //char mask7 = "29ee6-159ec";

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
