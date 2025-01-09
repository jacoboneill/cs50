#include <stdio.h>

int main(){
  int size = 1024;
  int scores[size];
  int garbage_count = 0;

  for(int i = 0; i < size; i++){
    if(scores[i] != 0){
      garbage_count++;
    }
  }

  printf("Garbage Values Count: %i\n", garbage_count);

  return 0;
}
