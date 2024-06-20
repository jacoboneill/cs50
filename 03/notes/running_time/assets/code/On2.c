#include <stdio.h>

int main(){
    int arr[] = {1, 2, 3, 4};
    int arr_len = 4;

    for(int i = 0; i < arr_len; i++){
        for(int j = 0; j < arr_len; j++){
            printf("%i + %i = %i\n", arr[i], arr[j], arr[i] + arr[j]);
        }
    }
}

