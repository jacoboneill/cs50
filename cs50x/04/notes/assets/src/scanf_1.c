#include <stdio.h>

int get_int(char* message);

int main(){
  int n = get_int("n: ");
  printf("n: %i\n", n);

  return 0;
}

int get_int(char* message){
  printf("%s", message);

  int number;
  scanf("%i", &number);
  return number;
}
