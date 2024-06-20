# Searching

## Array
An array is a contiguous (back-to-back) data structure of the same type:
```c
int numbers[] = {1, 5, 15, 20, 50, 100, 500};
```

## Searching Algorithms
Searching algorithms take an array as input, and attempt to give a `boolean` as to whether the value you are searching for is in the array.

## Linear Search
When the data isn't sorted, you brute-force by going through all the values in the array until you find it.
```c
#include <stdbool.h>
#include <stdio.h>

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
```

## Binary Search
When the data is sorted, you can use a *"divide and conquer"* technique where you check the middle, if the target is larger then take the right side of the array and try again, if the target is smaller then take the left side and do it again, else you have the value there or the value doesn't exist.
```c
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
```
