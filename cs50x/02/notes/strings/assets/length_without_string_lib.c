#include <cs50.h>
#include <stdio.h>

int length(string str);

int main(){
  string name = get_string("Name: ");
  printf("%s is %i characters long\n", name, length(name));
}

int length(string str){
  int i = 0;
  while(str[i] != '\0'){
    i++;
  }
  return i;
}
