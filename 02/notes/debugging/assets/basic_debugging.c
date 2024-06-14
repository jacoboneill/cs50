#include <stdio.h>

void buggy();
void debug();
void fixed();

int main(){
  printf("Buggy code:\n");
  buggy();
  printf("\n");

  printf("Debug code:\n");
  debug();
  printf("\n");

  printf("Fixed code:\n");
  fixed();
  printf("\n");
}

void buggy(){
  for (int i = 0;i <= 3; i++) { 
    printf("#");
  }
  printf("\n");
}

void debug(){
  for (int i = 0;i <= 3; i++) { 
    printf("i is %i | ", i); // Added to see what i is
    printf("#");
    printf("\n"); // Added to make debug easier
  }
  printf("\n");
}

void fixed(){
  for (int i = 0; i < 3; i++) {
    printf("#");
  }
  printf("\n");
}

