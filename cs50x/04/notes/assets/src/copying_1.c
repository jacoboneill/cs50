#include <stdio.h>
#include <ctype.h>

int main(){
    char* s = "Hello";
    char* t = s;

    t[0] = toupper(t[0]);

    printf("%s, ", s);
    printf("%s\n", t);
    
    return 0;
}

// Output: 1ello, 1ello
