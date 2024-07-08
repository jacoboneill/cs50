#include <stdio.h>
#include <stdlib.h>

#define MAX 16

int main(){
  char* s = malloc(MAX);

  printf("s: ");
  scanf("%s", s);
  printf("s: %s\n", s);

  free(s);

  return 0;
}
