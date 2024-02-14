// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Variables
unsigned int hash_value;
unsigned int word_count;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 5000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_value = hash(word);
    node *checker = table[hash_value];
    while (checker != NULL)
    {
        if (strcasecmp(word, checker->word) == 0)
        {
            return true;
        }
        checker = checker->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int total = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        hash_value = hash(word);
        n->next = table[hash_value];
        table[hash_value] = n;
        word_count++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *p;
    for (int i = 0; i < N; i++)
    {
        p = table[i];
        while (p != NULL)
        {
            node *temp = p;
            p = p->next;
            free(temp);
        }
    }
    if (p == NULL)
    {
        return true;
    }
    return false;
}

// int main(void)
// {
//     load("dictionaries/large");

//     for (int i = 0; i < N;i++)
//     {
//         node *p = table[i];
//         while (p != NULL)
//         {
//             printf("%s\n",p->word);
//             p = p->next;
//         }

//     }
//     printf("%u\n", word_count);

//     unload();

//     return 0;
// }
