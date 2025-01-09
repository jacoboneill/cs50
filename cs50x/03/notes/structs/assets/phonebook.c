#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
  char* name;
  char* number;
} person;

int check_args(int argc, char* argv[]);
int search(int count, person people[], char* target_name);

int main(int argc, char* argv[]){
  // Check arguments
  if(check_args(argc, argv) != 0){
    return 1;
  }

  // Data Input
  int count = 3;
  person people[] = {
    {"jacob", "07123456789"},
    {"john", "07234567891"},
    {"jane", "07345678912"}
  };

  // Format input to be all lower case
  char* target_name = argv[1];
  for(int i = 0; i < strlen(target_name); i++){
    target_name[i] = tolower(target_name[i]);
  }

  // Output for search
  int index = search(count, people, target_name);
  if(index == -1){
    printf("%s not found in phonebook\n", target_name);
    return 1;
  } else {
    printf("%s: %s\n", target_name, people[index].number);
    return 0;
  }
}

int check_args(int argc, char* argv[]){
  if(argc != 2){
    printf("Usage: ./phonebook target_name\n");
    return 1;
  } else {
    return 0;
  }
}

int search(int count, person people[], char* target_name){
  for(int i = 0; i < count; i++){
    if(strcmp(people[i].name, target_name) == 0){
      return i;
    }
  }
  return -1;
}
