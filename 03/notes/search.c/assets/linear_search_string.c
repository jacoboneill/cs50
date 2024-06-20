#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_argc(int argc);
int linear_search(int datac, char* datav[], char* target);

int main(int argc, char* argv[]){
  if(check_argc(argc) == 1){
    return 1;
  }

  int datac = 6;
  char* datav[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
  char* target = argv[1];
  int index = linear_search(datac, datav, target);
  if(index == -1){
    printf("Target: %s not found\n", target);
    return 1;
  } else {
    printf("Target: %s found at index: %i\n", target, index);
    return 0;
  }
}

int check_argc(int argc){
  if(argc != 2){
    printf("Usage: ./linear_search target\n");
    return 1;
  } else {
    return 0;
  }
}

int linear_search(int datac, char* datav[], char* target){
  for(int i = 0; i < datac; i++){
    if(strcmp(datav[i], target) == 0){
      return i;
    }
  }
  return -1;
}
