#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

void homegrown(string s);
void ctype_function(string s);

int main(){
  string s = get_string("Before   : ");
  homegrown(s);
  ctype_function(s);

}

void homegrown(string s){
  printf("Homegrown: ");
  int i = 0;
  while(s[i] != '\0'){
    if(s[i] >= 'a' && s[i] <= 'z'){
      printf("%c", s[i] - ('a' - 'A'));
    } else {
      printf("%c", s[i]);
    }
    i++;
  }
  printf("\n");
}

void ctype_function(string s){
  printf("ctype    : ");
  int i = 0;
  while(s[i] != '\0'){
    printf("%c", toupper(s[i]));
    i++;
  }
  printf("\n");
}
