// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 234;

// Hash table
node *table[N];

// Amount of words in dictionary
unsigned int sizeOfDictionary = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_code = hash(word);

    node *ptr = table[hash_code];

    while (ptr != NULL)
    {
        if (strcasecmp(word, ptr->word) == 0)
            return true;
        else
            ptr = ptr->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // must be between 0 and N - 1, inclusive

    int index = 0;
    int n = strlen(word);
    if (strlen(word) > 10)
        n = 10;

    for (int i = 0; i < n; i++)
    {
        // Sum of all letter numbers
        if (isalpha(word[i]))
            index += (toupper(word[i]) - 'A');
    }

    // Returns a sum of numerical values of letters, with a limit of the first 9 letters for larger words
    // 9 * 26 = 234 possible answers for index
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open file
    FILE *openFile = fopen(dictionary, "r");
    if (openFile == NULL)
    {
        return false;
        sizeOfDictionary = 0;
    }

    // Read strings of words into an array
    char buffer[LENGTH + 1];
    while (fscanf(openFile, "%s", buffer) != EOF)
    {
        // Allocate node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
            return false;

        // Copy data into each node
        strcpy(n->word, buffer);

        // Change pointers so each node moves to the start of a linked list
        int arrayIndex = hash(n->word);
        n->next = table[arrayIndex];
        table[arrayIndex] = n;

        // Add word to size
        sizeOfDictionary++;
    }

    fclose(openFile);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return sizeOfDictionary;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *ptr = NULL;
    node *temp = NULL;
    for (int i = 0; i < N; i++)
    {
        ptr = table[i];
        while (ptr != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }
    return true;
}
