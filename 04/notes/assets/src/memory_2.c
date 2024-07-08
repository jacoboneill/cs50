#include <stdio.h>

int main(){
  int n = 50;
  int *p_n = &n;
  printf("%p = %i\n", p_n, *p_n);
}
