#include <stdio.h>

void print_array(int array_length, int array[], char* message);

int main(){
  int arr[] = {7,2,5,4,1,6,0,3};
  int arr_len = 8;

  print_array(arr_len, arr, "Starting Array: ");

  for(int i = 0; i < arr_len; i++){
    int s_val = arr[i];
    int s_index = i;
    for(int j = i + 1; j < arr_len; j++){
      if(arr[j] < s_val){
        s_val = arr[j];
        s_index = j;
      }
    }
    int temp = arr[i];
    arr[i] = s_val;
    arr[s_index] = temp;
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
