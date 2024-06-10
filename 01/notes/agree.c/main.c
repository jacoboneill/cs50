#include <cs50.h>
#include <stdio.h>

int main(){
  char c = get_char("Do you agree? ");

  if(c == 'y' || c == 'Y'){
    printf("You agree.\n");
  } else if(c == 'n' || c == 'N'){
    printf("You don't agree.\n");
  }
}
