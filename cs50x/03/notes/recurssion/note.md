# Recurssion

Recurssion is when a function calls itself and is an alternative to a iterative approach by using loops. For example

```c
#include <stdio.h>

void recurssive(int index, int max);
void iterative(int start, int max);

int main(){
    int start = 0;
    int max = 5;

    recurssive(start, max);
    printf("------------\n");
    iterative(start, max);
}

void recurssive(int index, int max){
    printf("Hello, world\n");
    if(index < max - 1){
        recurssive(index + 1, max);
    }
}

void iterative(int start, int max){
    for(int i = start; i < max; i++){
        printf("Hello, world\n");
    }
}
```

## Mario Recurssive

```c
#include <stdio.h>

void draw(int n);

int main(){
    int height = 4;
    draw(height);
}

void draw(int n){
    if(n > 1){
        draw(n - 1);
    }

    for(int i = 0; i < n; i++){
        printf("#");
    }
    printf("\n");
}
```
