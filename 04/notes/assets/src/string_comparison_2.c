#include <stdio.h>
#include <string.h>

int main(){
  char* a = "Hello";
  char* b = "world";

  if(strcmp(a, b) == 0){
    printf("Same\n");
    return 0;
  } else {
    printf("Not same\n");
    return 1;
  }
}
