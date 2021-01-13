// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

FILE *file = NULL;
int word_number = 0;

node *insert(node *head, char word[]);

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int index = hash(word);
    for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
    {
        // compare words ignoring case
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return tolower(word[0]) % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open file");
        return false;
    }

    node *head = NULL;
    char word[LENGTH + 1];
    int index;

    // read words from file and insert them into table depending on hash value
    while (fscanf(file, "%s", word) != EOF)
    {
        word_number++;
        
        index = hash(word);
        head = table[index];
        table[index] = insert(head, word);
    }

    return true;
}

// Inserts word into linked list that starts with head, returns the new head of the list
node *insert(node *head, char word[])
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        exit(1);
    }

    strcpy(n->word, word);
    n->next = head;
    head = n;

    // return new head of the list
    return head;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_number;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    
    fclose(file);
    return true;
}

