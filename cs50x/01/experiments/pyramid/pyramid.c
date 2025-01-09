#include <stdio.h>

int main(){
  int max = 10;
  char symbol = '*';

  for(int i = 0; i < max; i++){
    for(int j = 0; j < max - i - 1; j++){
      printf(" ");
    }
    for(int j = 0; j < (2*i) + 1; j++){
      printf("%c", symbol);
    }
    printf("\n");
  }
}

//      *      1
//     ***     3
//    *****    5
//   *******   7
//  *********  9
//
// spaces = max - i
// stars  = 2i + 1
