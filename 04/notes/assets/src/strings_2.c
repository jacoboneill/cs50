#include <stdio.h>

void print_string(char* s){
  while(*s != '\0'){
    printf("%c", *s);
    s++;
  }
  printf("\n");
}

int main(){
  char* s = "HI!";
  print_string(s);
}

