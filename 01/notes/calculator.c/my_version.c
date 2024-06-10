#include <cs50.h>
#include <stdio.h>

int add(int a, int b){
  return a + b;
}

int minus(int a, int b){
  return a - b;
}

int mult(int a, int b){
  return a * b;
}

int div(int a, int b){
  return a / b;
}

int main(){
  int a = get_int("First number: ");
  int b = get_int("Second number: ");

  int operation = get_int("(1) Add\n(2) Subtract\n(3) Multiply\n(4) Divide\n");

  if(operation == 1){
    printf("%i + %i = %i\n", a, b, add(a, b));
  } else if(operation == 2){
    printf("%i - %i = %i\n", a, b, minus(a, b));
  } else if(operation == 3){
    printf("%i x %i = %i\n", a, b, mult(a, b));
  } else if(operation == 4){
    printf("%i ÷ %i = %i\n", a, b, div(a, b));
  } 
}
