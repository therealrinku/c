/*
  stack in c
  push, pop, peek, isEmpty, isFull, getMax, getMin
*/


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int stack[MAX_SIZE];
int size = 0;

void push(void);
void pop(void);
void isEmpty(void);
void isFull(void);
void getMax(void);
void getMin(void);
void printStack(void);

// TODO:
// void increaseStackSize(void);

int main(void){
  printf("\n----Welcome to the stack simulator in C----");

  while(true){
    printf("\n1. Add to the stack\n");
    printf("2. Pop from the stack\n");
    printf("3. Get max from the stack\n");
    printf("4. Get min from the stack\n");
    printf("5. Check if stack is full\n");
    printf("6. Check if stack is empty\n");
    printf("7. Print the stack\n");
    printf("8. Quit\n");

    int choice;
    printf("Enter your choice:");
    scanf("%i", &choice);

    if(choice == 8){
      break;
    }

    switch(choice){
      case 1:{
        push();
        break;
      }
      case 2:{
        pop();
        break;
      }
      case 3:{
        getMax();
        break;
      }
      case 4:{
        getMin();
        break;
      }
      case 5:{
        isFull();
        break;
      }
      case 6:{
        isEmpty();
        break;
      }
      case 7:{
        printStack();
        break;
      }
    }
  }
  
  return 0;
}

void push(){
  printf("\n");
  int value;
  printf("Enter the number you want to push:");
  scanf("%i", &value);

  if(size >= MAX_SIZE){
    printf("Stack is full.");
    return;
  }
  
  stack[size++] = value;
}

void pop(){
  printf("\n");
  int value;

  if(size > 0){
    printf("The poped value is %i", stack[size - 1]);
    size--;
  }else{
    printf("Stack is empty");
  }
}

void isEmpty(){
  printf("\n");

  if(size > 0){
    printf("Stack is not empty");
  }else{
    printf("Stack is empty");
  }
}

void isFull(){
  printf("\n");

  if(size < MAX_SIZE){
    printf("Stack is not full");
  }else{
    printf("Stack is full");
  }
}

void getMax(){
  printf("\n");

  if(size == 0){
    printf("Stack is empty");
    return;
  }
  
  int max = stack[0];

  for(int i=1;i<size;i++){
    max = MAX(stack[i], max);
  }

  printf("Maximum value is %i", max);
}

void getMin(){
  printf("\n");

  if(size == 0){
    printf("Stack is empty");
    return;
  }

  int min = stack[0];

  for(int i=1;i<size;i++){
    min = MIN(stack[i], min);
  }

  printf("Minimum value is %i", min);
}

void printStack(){
  printf("\n");

  if(size == 0){
    printf("Stack is empty");
    return;
  }

  for(int i=0;i<size;i++){
    printf("%i->", stack[i]);
  }
}
