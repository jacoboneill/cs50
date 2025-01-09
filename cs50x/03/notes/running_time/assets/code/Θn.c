#include <stdio.h>

int main(){
  char str[] = "Hello, world";
  int str_len = 0;

  while(str[str_len] != '\0'){
    str_len++;
  }

  printf("The length of \"%s\" is %i\n", str, str_len);
}

