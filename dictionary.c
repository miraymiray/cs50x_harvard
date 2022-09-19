// Implements a dictionary's functionality

#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
int counterWord = 0;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int key = hash(word);
    
    node* nodePointer = table[key];
    
    while(nodePointer != NULL)
    {
        
        if(strcasecmp(nodePointer->word, word) == 0)
        {
            return true;
        }
        
        nodePointer = nodePointer->next;
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int v = 0;
    for(int i=0; word[i] !='\0'; i++)
    {
        v += tolower(word[i]);
    }
    return v % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE* flPtr = fopen(dictionary, "r");
    if(flPtr == NULL)
    {
        return false;
    }
    for(int i=0; i<N; i++)
    {
        table[i] = NULL;
    }
    
    char temporary[LENGTH+1];
    
    while(fscanf(flPtr, "%s\n", temporary) != EOF)
    {
        node* temporaryNode = malloc(sizeof(node));
        
        strcpy(temporaryNode->word, temporary);
        
        int key = hash(temporary);
        
        if(table[key] == NULL)
        {
            temporaryNode->next = NULL;
            table[key] = temporaryNode;
        }
        else
        {
            temporaryNode->next = table[key];
            table[key] = temporaryNode;
        }
        counterWord++;
    }
    fclose(flPtr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counterWord;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i=0; i<N; i++)
    {
        node* nodePointer = table[i];
        
        while(nodePointer != NULL)
        {
            node* trash = nodePointer;
            nodePointer = nodePointer->next;
            free(trash);
        }
        
        table[i] = NULL;
    }
    return true;
}
