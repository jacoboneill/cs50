#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 42

int main(){
  FILE* file = fopen("./small", "r");
  if(file == NULL){
    return 1;
  }

  char buffer[LENGTH + 1];

  while(fscanf(file, "%s", buffer) != EOF){
    printf("%s |", buffer);
  }

  printf("\n");
  
  fclose(file);
}
