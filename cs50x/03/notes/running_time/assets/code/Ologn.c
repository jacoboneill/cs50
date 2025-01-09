#include <stdio.h>

int bin_search(int arr_len, int* arr, int target);

int main(int argc, char* argv[]){
  int arr[] = {1, 2, 3, 4};
  int arr_len = 4;
  int target = 3;

  int bin_search_result = bin_search(arr_len, arr, target);
  if(bin_search_result == -1){
    printf("Target: %i not found.\n", target);
  } else{
    printf("Target: %i found at index %i\n", target, bin_search_result);
  }
}

int bin_search(int arr_len, int* arr, int target){
  int start = 0;
  int end = arr_len - 1;

  while(start <= end){
    int middle = start + (end - start) / 2;
    if(target == arr[middle]){
      return middle;
    } else if(target > arr[middle]){
      start = middle + 1;
    } else if(target < arr[middle]){
      end = middle;
    }
  }

  return -1;
}
