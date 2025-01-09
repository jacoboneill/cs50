#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int check_argc(int argc);
int check_argv(char* arg);
int linear_search(int datac, int datav[], int target);

int main(int argc, char* argv[]){
  if(check_argc(argc) == 1){
    return 1;
  } else if(check_argv(argv[1]) == 1){
    return 1;
  }

  int datac = 7;
  int datav[] = {20, 500, 10, 5, 100, 1, 50};
  int target = atoi(argv[1]);
  int index = linear_search(datac, datav, target);
  if(index == -1){
    printf("Target: %i not found\n", target);
    return 1;
  } else {
    printf("Target: %i found at index: %i\n", target, index);
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

int check_argv(char* arg){
  int i = 0;
  while(arg[i] != '\0'){
    if(!isdigit(arg[i])){
      printf("Target should only be digits.\n");
      return 1;
    }
    i++;
  }
  return 0;
}

int linear_search(int datac, int datav[], int target){
  for(int i = 0; i < datac; i++){
    if(datav[i] == target){
      return i;
    }
  }
  return -1;
}
