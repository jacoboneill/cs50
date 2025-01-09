#include <cs50.h>
#include <stdio.h>
#include <string.h>

void inefficient(string s);
void more_efficient(string s);
void efficient(string s);

int main(){
  string s = get_string(">  ");
  inefficient(s);
  more_efficient(s);
  efficient(s);
}

void inefficient(string s){
  printf("1. ");
  for(int i = 0; i < strlen(s); i++){
    printf("%c", s[i]);
  }
  printf("\n");
}

void more_efficient(string s){
  printf("2. ");
  for(int i = 0, length = strlen(s); i < length; i++){
    printf("%c", s[i]);
  }
  printf("\n");
}

void efficient(string s){
  printf("3. ");
  int i = 0;
  while(s[i] != '\0'){
    printf("%c", s[i]);
    i++;
  }
  printf("\n");
}
