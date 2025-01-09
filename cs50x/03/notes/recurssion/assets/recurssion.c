#include <stdio.h>

void recurssive(int index, int max);
void iterative(int start, int max);

int main(){
  int start = 0;
  int max = 5;

  recurssive(start, max);
  printf("------------\n");
  iterative(start, max);
}

void recurssive(int index, int max){
  printf("Hello, world\n");
  if(index < max - 1){
    recurssive(index + 1, max);
  }
}

void iterative(int start, int max){
  for(int i = start; i < max; i++){
    printf("Hello, world\n");
  }
}

