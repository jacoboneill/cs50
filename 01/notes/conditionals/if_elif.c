#include <stdio.h>

int main(){
  int x = 9;
  int y = 9;

  if(x < y){
    printf("x is less than y\n");
  } else if(x > y){
    printf("x is not less than y\n");
  } else if(x == y){
    printf("x is equal to y\n");
  }
}
