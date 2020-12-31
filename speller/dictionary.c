// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
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

unsigned int word_load_count = 0;
node *new_node;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Obtain hashcode from lowercase word
    unsigned int hashcode = hash(word);

    // Access hashtable through cursor and traverse linked list
    node *cursor = table[hashcode];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            // printf("%s is in dictionary\n", word);
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    free(cursor);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Hash function djb2 by Dan Bernstein
    unsigned long hash = 5381;
    int c;
    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c);
        /* hash * 33 + c */
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary
    FILE *dict = fopen(dictionary, "r");
    if (!dict)
    {
        return false;
    }

    // Allocate memory for pointers
    char *current_word = malloc(LENGTH + 1);
    if (!current_word)
    {
        return false;
    }

    // Start loop. Store dictionary word on current word and return status to is_EOF
    while (fscanf(dict, "%s", current_word) != EOF)
    {
        // Copy current word to new node
        new_node = malloc(sizeof(node));
        if (!new_node)
        {
            unload();
            return false;
        }
        strcpy(new_node->word, current_word);

        // Get a hashcode for current word and place it in hash table
        unsigned int hashcode = hash(new_node->word);

        if (table[hashcode] == NULL)
        {
            table[hashcode] = new_node;
        }
        else
        {
            new_node->next = table[hashcode];
            table[hashcode] = new_node;
        }

        // Update loaded word count
        word_load_count++;
    }

    // Close and free
    free(current_word);
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_load_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *head = NULL;
            node *cursor = head;

            while (cursor != NULL)
            {
                node *temp = cursor;
                cursor = cursor->next;
                free(temp);

            }
            free(table[i]);
        }


    }
    // free(new_node);
    return true;
}
