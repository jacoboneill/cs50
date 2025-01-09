#include <stdio.h>
#include <string.h>
typedef char* string;

int main(){
  int a = 1;
  float b = 3.14;
  char c = 'z';
  signed long int d = 1234567890L;
  string e = "hello, world";

  printf("Integer: %i\nFloat: %f\nCharacter: %c\nSigned Long Integer: %li\nString: %s\n", a, b, c, d, e);
}
