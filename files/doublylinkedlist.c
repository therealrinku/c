// lets build doubly linked list in c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  int val;
  struct node* prev;
  struct node* next;
} node;


node* list = NULL;
node* tail = NULL;
int size = 0;

void add(void);
void traverse(void);
void traverseInReverse(void);
void removeL(void);

int main(void){
  printf("---welcome to linked list simulator in c---\n");

  while(true){
    printf("\n1. Add item to linkedlist\n");
    printf("2. Traverse\n");
    printf("3. Traverse in reverse order\n");
    printf("4. Remove item\n");
    printf("5. Get Largest Number\n");
    printf("6. Get Smallest Number\n");
    printf("7. Quit\n");
    printf("Type your command:");

    int cmd;
    scanf("%i", &cmd);

    if(cmd == 7) {
      // freeList();
      break;
    }

    switch(cmd){
      case 1:{
        add();
        break;
      }
      case 2:{
        traverse();
        break;
      }
      case 3:{
        traverseInReverse();
        break;
      }
      case 4:{
        removeL();
        break;
      }
      case 5:{
        // printLargestNumber();
        break;
      }
      case 6:{
        // printSmallestNumber();
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

void add(){
  int a;
  printf("Type the value you want to add: ");
  scanf("%i", &a);

  node* new_node =  malloc(sizeof(node));

  new_node->val = a;
  new_node->prev = NULL;
  new_node->next = NULL;

  if(!list){
    list = new_node;
    tail = new_node;
  } else{
    new_node->prev = tail; 
    tail->next = new_node; 
    tail = new_node;      
  }

  size++;
}

void traverse(){
  node* current = list;
  
  while(current){
    printf("Value: %i", current->val);
    current = current->next;
  }
}

void traverseInReverse(){
  node* current = tail;

  while(current){
    printf("Value: %i", current->val);
    current= current->prev;
  }
}


void removeL(void){
  int pos;
  printf("Enter position of element you want to delete:");
  scanf("%i", &pos);

  if(pos<=0 || pos>size){
    printf("Invalid position entered");
    return;
  }

  node* current = list;

  if(pos == 1){
    list = current->next;
    if(list){
      list->prev = NULL;
    }else{
      tail = NULL;
    }

    free(current);
    size--;
    return;
  }

  if(pos == size){
    current = tail;
    tail =  tail->prev;
    tail->next = NULL;
    free(current);
    size--;
    return;
  }

  int i = 1;
  while(i < pos - 1){
    current = current->next;
    i++;
  }

  node* temp = current->next;
  current->next = temp->next;
  if(temp->next){
    node* tempNext = temp->next;
    tempNext->prev = current;
  }

  size--;
}

// 1, 2, 3, 4 ,5 ,6 , 7
