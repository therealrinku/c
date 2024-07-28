/*
  command line based todo app
  crud
  save todo list on the file at the end of the program ??
  load todos from file when program opens aka data will persist
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
  int id;
  // 257 including null character :)
  char description[257];
  int is_completed;
} Todo;

#define MAX_TODOS 100
#define TODOS_FILE "todo_file.txt"

Todo todos[MAX_TODOS];
int todos_len = 0;

void load_todos(void);
void save_todos(void);

void view_todos(void);
void add_todo(void);
void delete_todo(void);
void mark_done(void);


int main(void){
  load_todos();

  while(true){
    int cmd;

    printf("\n----COMMANDLINE TODO APPLICATION----\n");
    printf("1. Add todo\n");
    printf("2. View todos\n");
    printf("3. Delete todo\n");
    printf("4. Mark todo done\n");
    printf("5. Quit\n");
    printf("Type your choice:");

    scanf("%i", &cmd);

    //clean the input buffer, so fgets works properly
    char a;
    while((a=getchar()) != '\n'){}

    switch(cmd){
      case 1:{
        add_todo();
        break;
      }
      case 2:{
        view_todos();
        break;
      }
      case 3:{
        view_todos();
        delete_todo();
        break;
      }
      case 4:{
        view_todos();
        mark_done();
        break;
      }
      case 5:{
        save_todos();
        exit(0);
      }
    }
  }

  return 0;
}

void view_todos(void){
  printf("\n");
  for(int i=0;i<todos_len;i++){
    printf("Todo Id:%i: %s, %s\n", todos[i].id, todos[i].description, todos[i].is_completed == 1 ? "done": "not-done");
  }
}


void delete_todo(void){
  int id;
  printf("Enter id of todo you want to delete:");
  scanf("%i", &id);

  for(int i=0;i<todos_len;i++){
    if(todos[i].id ==id){
      //swap to the last element:: easy peasy lemon squeasy isnt' it
      todos[i] = todos[todos_len - 1];
      todos_len--;
      printf("Todo deleted\n");
      return;
    }
  }

  printf("Todo with given id was not found\n");
}


void mark_done(void){
  int id;
  printf("Enter id of todo you want to mark as done:");
  scanf("%i", &id);

  for(int i=0;i<todos_len;i++){
    if(todos[i].id ==id){
      todos[i].is_completed = 1;
      printf("Todo marked as done!\n");
      return;
    }
  }

  printf("Todo with given id was not found\n");
}

void add_todo(void){
  if(todos_len >= MAX_TODOS){
    printf("Todo list is full");
    return;
  }

  Todo new_todo;
  new_todo.id = todos_len + 1;
  new_todo.is_completed = 0;

  printf("Enter new todo description:");
  // fgets puts null terminator by itself there, thanks fgets!!
  fgets(new_todo.description, 256, stdin);

  todos[todos_len++] = new_todo;
}

void load_todos(void){
  FILE *file = fopen(TODOS_FILE, "r");
  if (file) {
      while (fscanf(file, "%d %[^\t] %d\n", &todos[todos_len].id, todos[todos_len].description, &todos[todos_len].is_completed) != EOF) {
          todos_len++;
      }
      fclose(file);
  }
}

void save_todos(void){
  FILE *file = fopen(TODOS_FILE, "w");
  for (int i = 0; i < todos_len; i++) {
      fprintf(file, "%d\t%s\t%d\n", todos[i].id, todos[i].description, todos[i].is_completed);
  }
  fclose(file);
}
