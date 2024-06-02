/*
  linkedlist in c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  int val;
  struct Node* next; 
} Node;

Node *list = NULL;
int size = 0;


void addToList(void);
void removeFromList(void);
void updateList(void);
void printList(void);
void freeList(void);

int main(void){
  printf("---welcome to linked list simulator in c---\n");
  
  while(true){
    printf("\n1. Add item to linkedlist\n");
    printf("2. Remove item from linkedlist\n");
    printf("3. Update item in linkedlist\n");
    printf("4. Print linkedlist\n");
    printf("5. Quit\n");
    printf("Type your command:");

    int cmd;
    scanf("%i", &cmd);

    if(cmd == 5) {
      freeList();
      break;
    }

    switch(cmd){
      case 1:{
        addToList();
        break;
      }
      case 2:{
        removeFromList();
        break;
      }
      case 3:{
        updateList();
        break;
      }
      case 4:{
        printList();
        break;
      }
      default:{
        printf("Invalid command");
        break;
      }
    }
  }

  return 0;
}


void freeList(void){
  Node *curr = list;
  
  while(curr != NULL){
    Node *next = curr->next;
    free(curr);
    curr = next;
  }

  list = NULL;
  size = 0;
}


void addToList(void){
  int val;

  printf("Type the number you want to add:");
  scanf("%i", &val);
  
  Node *newNode = malloc(sizeof(Node));
  newNode->val = val;
  newNode->next = list;
  list = newNode;
  size++;
}

void removeFromList(void){
  int pos;

  printf("Type the position of the number you want to remove:");
  scanf("%i", &pos);

  if(pos<=0 || pos > size){
    printf("Invalid position");
    return;
  }

  int i = 0;

  Node *curr = list;

  if(pos == 1){
    curr = curr->next;
    free(curr);
    size--;
  } else{
    for(int i=1;i<pos-1;i++){
      curr = curr->next;
    }

    Node *temp = curr->next;
    curr->next = temp->next;
    size--;
    free(temp);
  }
}

void updateList(void){
  int pos;

  printf("Type the position of the number you want to update:");
  scanf("%i", &pos);

  int i = 0;
  if(pos<=0 || pos > size){
    printf("Invalid position");
    return;
  }

  int val;
  printf("Type the new number:");
  scanf("%i", &val);

  Node *curr = list;

  if(pos == 1){
    list->val = val;
  }else{
    for(int i=1;i<pos;i++){
      curr = curr->next;
    }

    curr->val = val;
  }
}

void printList(void){
  Node *curr = list;
  
  for(int i=0;i<size;i++){
    printf("%i-->", curr->val);
    curr = curr->next;
  }

  free(curr);
}
