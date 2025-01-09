#include <stdbool.h>
#include <stdio.h>

bool binary_search(int array_length, int* array, int target);

int main(){
  int example_array_length = 7;
  int example_array[] = {1, 5, 15, 20, 50, 100, 500};
  int example_target = 5;

  bool is_found = binary_search(example_array_length, example_array, example_target);
  printf("Is %i in array? %s\n", example_target, is_found ? "It is found!" : "It wasn't found.");
}

bool binary_search(int array_length, int* array, int target){
  int start = 0;
  int end = array_length - 1;
  int middle;

  while(end - start > 0){
    middle = ((end - start) / 2) + start;
    if(target == array[middle]){
      return true;
    } else if(target > array[middle]){
      start = middle + 1;
    } else if(target < array[middle]){
      end = middle - 1;
    }
  }

  return false;
}
