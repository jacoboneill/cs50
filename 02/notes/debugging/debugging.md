# Debugging
# Using `printf`

> See ./assets/example_one.c for source code.

```c
#include <stdio.h>

int main(){
    for(int i = 0; i <= 3; i++){
        printf("#");
    }
    printf("\n");
}
```

The expected output is `###`, however the output is actually `####`.

## Debugging process

Use `printf` to see what the program is doing

```c
#include <stdio.h>

int main(){
    for(int i = 0; i <= 3; i++){
        printf("i is %i | ", i);
        printf("#");
        printf("\n");
    }
    printf("\n")
}
```
This now gives the output of:
```
i is 0 | #
i is 1 | #
i is 2 | #
i is 3 | #
```

We can now see that the loop is going too many times, and that there is four loops. To fix this, we can change the condition of the `for loop` to be `<` instead of `<=`.

## Fixed coe 
```c
#include <stdio.h>

int main(){
    for(int i = 0; i < 3; i++){
        printf("#");
    }
    printf("\n");
}
```

And now the output is `###`

# Using a Debugger
Instead of using printf's all over the place and having to remember to remove all of them when compiling, as well as constantly recompiling, we can use a debugger. This will allow us to be able to step over function's and keep a track of variable's values. This means that we don't have to keep compiling or remeber to remove `printf`'s.
To do this at [cs50.dev](http://cs50.dev) we can use the command `debug50`

# Rubber Ducky Debugging
Traditionally, you can use a rubber ducky to explain the program that you are programming to be able to pick up where mistakes have been made.
You can also use [cs50.ai](cs50.ai) to use the Harvard made ChatGPT.
