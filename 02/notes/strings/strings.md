# Strings

Strings in C are actually just arrays of characters.
`char string[] = "Hello, world\n";`

This is the equivelant of: `{'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '\n'}`

Which means, that you can do the following:
```c
#include <stdio.h>

int main(){
    char string[] = "HI!";

    for(int i = 0; i < 3; i++){
        printf("%c\n", string[i]);
    }
}
```

This will output:
```
H
I
!
```

However, strings also have a '\0' NUL byte at the end to denote the end of the string.
This means we can do the following:
```c
#include <stdio.h>

int main(){
    char string[] = "Hi!";

    int i = 0;
    while(string[i] != '\0'){
        printf("%c\n", string[i]);
        i++;
    }
}
```

And this will dynamically output:
```
H
i
!
```

and this is because `string` is actually `{'H', 'i', '!', '\0'}`

# String Lengths


