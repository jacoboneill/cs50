#include <stdio.h>

int lin_search(int arr_len, int* arr, int target);

int main(){
  int arr[] = {1, 2, 3, 4};
  int arr_len = 4;
  int target = 4;

  int lin_search_result = lin_search(arr_len, arr, target);

  if(lin_search_result == -1){
    printf("Target: %i not found.\n", target);
  } else {
    printf("Target: %i found at index %i\n", target, lin_search_result);
  }
}

int lin_search(int arr_len, int* arr, int target){
  for(int i = 0; i < arr_len; i++){
    if(arr[i] == target){
      return i;
    }
  }

  return -1;
}
