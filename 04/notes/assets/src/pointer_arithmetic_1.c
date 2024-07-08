#include <stdio.h>

void print(char* s);

int main(){
  char* s = "HI!";
  print(s);
}

void print(char* s){
  int offset = 0;
  while(*(s + offset) != '\0'){
    printf("%c", *(s + offset));
    offset++;
  }
  printf("\n");
}
