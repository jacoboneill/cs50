#include <stdio.h>

int main(){
    int a  = 1;
    int b = 2;

    if(a == b){
        printf("Same\n");
        return 0;
    } else {
        printf("Not same\n");
        return 1;
    }
}

// Output: Not same
// $? = 1
