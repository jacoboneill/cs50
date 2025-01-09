#include <stdlib.h>

int main(){
  int* x = malloc(3 * sizeof(int));
  x[1] = 72;
  x[2] = 73;
  x[3] = 33;
}
