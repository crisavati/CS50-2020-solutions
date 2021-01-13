#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LENGTH 5

typedef struct node
{
    char dic_word[LENGTH+1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

FILE *file = NULL;

unsigned int hash(const char *word);
node* insert(node *head, char w[]);

int main(void)
{
    // open file
    file = fopen("words.text", "r");
    if (file == NULL)
    {
        return 1;
    }

    node *head = NULL;
    char word[LENGTH+1];
    int index;
    // read words from file and insert them into table depending on hash value
    while (fscanf(file, "%s", word) != EOF) 
    {
        index = hash(word);
        head = table[index];
        table[index] = insert(head, word);
    }

    // print hash table
    for (int i = 0; i < N; i++)
    {
        for (node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
        {
            printf("%s\n", tmp->dic_word);
        }
    }
    
    
}

node* insert(node *head, char word[])
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        exit(1);
    }

    strcpy(n->dic_word, word);
    n->next = head;
    head = n;  

    // return new head of the list
    return head; 
}

unsigned int hash(const char *word)
{
    return word[0] % N;
}