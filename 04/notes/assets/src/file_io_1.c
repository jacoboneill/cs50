#include <stdio.h>
#include <stdlib.h>

#define MAX 16

char* get_string(char* msg);

int main(){
  FILE* file = fopen("phonebook.csv", "a"); // Open file phonebook.csv in append mode, returns a pointer to a file

  char* name = get_string("Name: ");
  char* number = get_string("Number: ");

  fprintf(file, "%s,%s\n", name, number); // Append name and number in csv file formatting

  fclose(file); // Close file

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
