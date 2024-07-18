// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int word_length = strlen(word);
    char l_word[word_length + 1];

    for (int i = 0; i < word_length; i++)
    {
        l_word[i] = tolower(word[i]);
    }
    l_word[word_length] = '\0';

    for (node *ptr = table[hash(word)]; ptr != NULL; ptr = ptr->next)
    {
        if (strcmp(ptr->word, l_word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];
    while (fscanf(file, "%s", buffer) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        strcpy(new_node->word, buffer);

        // Prepend new node to correct linked list
        new_node->next = table[hash(new_node->word)];
        table[hash(new_node->word)] = new_node;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int counter = 0;

    for (int i = 0; i < N; i++)
    {
        for (node *ptr = table[i]; ptr != NULL; ptr = ptr->next)
        {
            counter++;
        }
    }

    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *next;

    for (int i = 0; i < N; i++)
    {
        for (node *remove = table[i]; remove != NULL; remove = next)
        {
            next = remove->next;
            free(remove);
        }
    }

    return true;
}
