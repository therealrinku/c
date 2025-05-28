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

  // play with masks later?

  //gh
  //char mask1 = "b7258-7d495";
  //char mask2 = "05579-ade39";
  //char mask3 = "b3f09-87e61";
  //char mask4 = "a6584-74e6f";
  //char mask5 = "c61bc-e953e";
  //char mask6 = "bafcc-9373c";

  //gg
  //char mask8 = "50111873";
  //char mask9 = "12098493";
  //char mask10 = "02635803";
  //char mask11 = "58686070";
  //char mask12 = "60450784";
  //char mask13 = "11525664";
  //char mask14 = "05508766";

  //fd
  //char mask15 = "rzv2-90bs" 
  //char mask16 = "wve8-mlt2" 
  //char mask17 = "77zu-cscb"

  //ap
  //char mask18 = "2921-3381-3512"

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
