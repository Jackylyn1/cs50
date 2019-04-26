// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        //anfangsbuchstabe num auslesen
        int i = hash(word);
        //create new node
        node *n = malloc(sizeof(node));
        strcpy(n->word, word);
        n->next = hashtable[i];
        hashtable[i] = n;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int num = 0;
    for (int i = 0; i < N; i++)
    {
        node *hash = hashtable[i];
        while (hash)
        {
            num++;
            hash = hash->next;
        }
    }
    return num;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    // anfangsbuchstabe zahl suchen, dann in dics nachsehen, dann durchlaufen bis gefunden oder ende, else return true
    int start = hash(word);
    node *hash = hashtable[start];
    while (hash)
    {
        if (strcasecmp(hash->word, word) == 0)
        {
            return true;
        }
        hash = hash->next;
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    // alles durchlaufen, free every pointer, set hashtable to null
    for (int i = 0; i < N; i++)
    {
        node *hash = hashtable[i];
        while (hash)
        {
            node *hash_old = hash;
            hash = hash->next;
            free(hash_old);
        }
        hashtable[i] = NULL;
    }
    return true;
}
