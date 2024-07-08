#include <stdio.h>

void swap(int a, int b);

int main(){
  int x = 1;
  int y = 2;

  printf("x: %i, y: %i | ", x, y);
  swap(x, y);
  printf("x: %i, y: %i\n", x, y);
}

void swap(int a, int b){
  int temp = a;
  a = b;
  b = temp;
}

// Output: x: 1, y: 2 | x: 1, y: 2

