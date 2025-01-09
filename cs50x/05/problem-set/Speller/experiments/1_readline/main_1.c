#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 16

int main(){
  FILE* file = fopen("./small", "r");
  if(file == NULL){
    return 1;
  }

  char buffer;
  char word[LENGTH + 1];
  int word_length = 0;

  while(fread(&buffer, sizeof(buffer), 1, file) != 0){
    
    if(buffer == '\n' || word_length >= LENGTH - 1){
      word[word_length + 1] = '\0';
      printf("%s | ", word);
      word_length = 0;
    } else {
      word[word_length] = buffer;
      word_length++;
    }
  }

  printf("\n");
  
  fclose(file);
}
