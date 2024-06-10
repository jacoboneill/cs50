#include <stdio.h>

void attemptOne(){
  int i = 3;
  while(i > 0){
    printf("meow\n");
    i--;
  }
}

void attemptTwo(){
  int i = 1;
  while(i <= 3){
    printf("meow\n");
    i++;
  }
}

void attemptThree(){
  int i = 0;
  while(i < 3){
    printf("meow\n");
    i++;
  }
}

void attemptFour(){
  for(int i = 0; i < 3; i++){
    printf("meow\n");
  }
}

int main(){
  printf("Attempt One:\n");
  attemptOne();
  printf("\n");

  printf("Attempt Two:\n");
  attemptTwo();
  printf("\n");

  printf("Attempt Three:\n");
  attemptThree();
  printf("\n");

  printf("Attempt Four:\n");
  attemptFour();
}
