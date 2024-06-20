# Structs

In C, we can create our own types by creating data structures. This can be done with the following syntax:
```c
typedef struct{
    char* name;
    char* phone_number;
} person;
```

This can be used to create an array with different bits of data, for example, a phonebook could be made in the following way:
```c
typedef struct{
    char* name;
    char* phone_number;
} person;

int main(){
    person people[] = {
        {"Jacob", "07123456789"},
        {"John", "07234567891"},
        {"Jane", "07345678912"}
    };
}
```

To then access these values you can use the following syntax:
```c
people[0].name;     // Jacob
people[0].number;   // 07123456789 
```

## phonebook.c Optimised
```c
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
```

```
Output:
> ./phonebook
Usage: ./phonebook target_name

> ./phonebook Jacob
jacob: 07123456789

> ./phonebook JoHn
john: 07234567891

> ./phonebook jane
jane: 07345678912

> ./phonebook jack
jack not found in phonebook
```
