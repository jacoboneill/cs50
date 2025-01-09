# Command Line Arguments

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string get_name();

int main(int argc, string argv[])
{
  string name;
  if(argc > 1){
    name = argv[1];
  } else {
    name = get_name();
  }

  printf("Welcome, %s!\n", name);
}

string get_name(){
  return get_string("Hello. What is your name?\n");
}
```
