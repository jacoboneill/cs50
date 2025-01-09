#include <stdio.h>

void print_array(int array_length, int array[], char* message);

int main(){
  int arr[] = {7,2,5,4,1,6,0,3};
  int arr_len = 8;

  print_array(arr_len, arr, "Starting Array: ");

  for(int i = 0; i < arr_len; i++){
    for(int j = 0; j < arr_len - i - 1; j++){
      if(arr[j] > arr[j + 1]){
        int temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }

  print_array(arr_len, arr, "Final Array   : ");
}

void print_array(int array_length, int array[], char* message){
  printf("%s", message);
  for(int i = 0; i < array_length; i++){
    printf("%i ", array[i]);
  }
  printf("\n");
}
