#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LENGTH 45

typedef struct node{
  char word[LENGTH + 1];
  struct node* next;
} node;

node* table[26];

int hash(char* input);
node* initNode(char* word);
void appendNode(node** list, node* new_node);

int main(int argc, char* argv[]){
  for(int i = 1; i < argc; i++){
    node* new_node = initNode(argv[i]);
    appendNode(&table[hash(new_node -> word)], new_node);
  }
  
  printf("All words with the hash: %i:\n", hash("h"));
  for(node* ptr = table[hash("h")]; ptr != NULL; ptr = ptr -> next){
    printf("%s\n", ptr -> word);
  }
  for(node* ptr = table[hash("h")]; ptr != NULL; ptr = ptr -> next){
    free(ptr);
  }
}

int hash(char* input){
  return toupper(input[0]) - 'A';
}

node* initNode(char* word){
  node* new_node = malloc(sizeof(node));
  strcpy(new_node -> word, word);
  return new_node;
}

void appendNode(node** list, node* new_node){
  new_node -> next = *list;
  *list = new_node;
}
