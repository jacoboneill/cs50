#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(){
  string name = get_string("Name: ");
  int length = strlen(name);
  printf("%s is %i characters long\n", name, length);
}
