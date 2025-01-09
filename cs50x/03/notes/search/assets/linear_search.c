#include <stdio.h>
#include <stdbool.h>

bool linear_search(int array_length, int* array, int target);

int main(){
  int example_array_length = 7;
  int example_array[] = {1, 5, 15, 20, 50, 100, 500};
  int example_target = 20;

  bool is_found = linear_search(example_array_length, example_array, example_target);
  printf("Is %i in array? %s\n", example_target, is_found ? "It is found!" : "It wasn't found.");
}

bool linear_search(int array_length, int* array, int target){
  for(int i = 0; i < array_length; i++){
    if(array[i] == target){
        return true;
    }
  }
  return false;
}

