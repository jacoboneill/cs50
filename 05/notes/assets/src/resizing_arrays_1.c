#include <stdio.h>
#include <stdlib.h>

void print_array(int* arr, int size);

int main(){
  // Initalise a new array of length three
  int* list = malloc(3 * sizeof(int));
  if(list == NULL){
    return 1;
  }

  // Add values 1, 2, 3 to list
  for(int i = 0; i < 3; i++){
    list[i] = i + 1;
  }
  
  // Print array 
  print_array(list, 3);

  // Add new value to dynamic array
  int new_value = 4;
  int* temp = malloc(4 * sizeof(int));
  if(temp == NULL){
    free(list);
    return 1;
  }

  // Add list values to temp
  for(int i = 0; i < 3; i++){
    temp[i] = list[i];
  }
  temp[3] = new_value;

  free(list);   // Forget where list used to be
  list = temp;  // And make list point to where temp is pointing
  
  print_array(list, 4);

  free(list);
  return 0;
}

void print_array(int* arr, int size){
  printf("[");

  for(int i = 0; i < size; i++){
    printf("%i", arr[i]);
    if(i != size - 1){
      printf(", ");
    }
  }

  printf("]\n");
}

