// string class in c
// TODO: improve and add more useful string functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct String {
  int len;
  int capacity;
  char* value;
  void (*append)(struct String* self, char *str);
};

void __append(struct String* self, char *str) {
  // check current string length then insert new string from len position beyond
  // realloc if len exceeds the capacity
  int current_length = strlen(self->value);
  int new_string_length = strlen(str);

  int final_string_length = current_length + new_string_length + 1;
  if(final_string_length >= self->capacity){
    self->value = realloc(self->value, final_string_length);
    self->capacity = final_string_length;
  }

  for(int i=0;i<new_string_length;i++){
    self->value[current_length + i] = str[i];
  }

  self->value[final_string_length - 1] = '\0';
  self->len = final_string_length - 1;
}

struct String *newString() {
  struct String *self = malloc(sizeof(struct String));
  // initial capacity 100, resize as necessary!!
  self->capacity = 100;
  self->len = 0;
  // NULL
  self->value = malloc(self->capacity * sizeof(char));
  self->append = &__append;

  return self;
}

int main(void) {
  struct String *mystring = newString();
  mystring->append(mystring, "hello");
  mystring->append(mystring, " ");
  mystring->append(mystring, "world!");
  printf("%s", mystring->value);
}
