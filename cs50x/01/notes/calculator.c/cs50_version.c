#include <cs50.h>
#include <stdio.h>

int add(int a, int b);
float div(int a, int b);

int main(){
  int x = get_int("x: ");
  int y = get_int("y: ");

  printf("%i\n", add(x, y));
  printf("%.20f\n", div(x, y));
}

int add(int a, int b){
  return a + b;
}

float div(int a, int b){
  return (float) a / (float) b;
}
