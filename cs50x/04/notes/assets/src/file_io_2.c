#include <stdio.h>
#include <stdlib.h>

#define MAX 16

char* get_string(char* msg);

int main(){
  FILE* file = fopen("phonebook.csv", "a");
  if(file == NULL) return 1;

  char* name = get_string("Name: ");
  if(name == NULL) return 1;

  char* number = get_string("Number: ");
  if(number == NULL) return 1;

  fprintf(file, "%s,%s\n", name, number);

  fclose(file);

  printf("Added contact %s @ %s\n", name, number);

  free(name);
  free(number);
  return 0;
}

char* get_string(char* msg){
  printf("%s", msg);
  char* input = malloc(MAX);
  scanf("%s", input);
  return input;
}
