// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

//return true if dictionary is loaded,else false
bool isloaded(void)
{
    for (int i=0;i<N;i++)
    {
        if( hashtable[i])
            return true;
    }
    return false;
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

        //initial a node to store word
        node *new=malloc(sizeof(node));
        //check if new==NULL
        if(new==NULL)
        {
            unload();
            return false;
        }
        //put the word in node,set next to NULL
        strcpy(new->word,word);
        new->next=NULL;
        //insert to the hashtable
        //check if there is already word in the link list
        //yes
        if(hashtable[hash(word)])
        {
            new->next=hashtable[hash(word)];
            hashtable[hash(word)]=new;
        }
         //no
        else
        {
            hashtable[hash(word)]=new;
        }
        //free(new);
    }


    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    //check if the dictionary is loaded
    if(isloaded())
    {
    //yes
    //returns number of words in dictionary
        int count=0;
        for(int i=0;i<N;i++)
        {
            for(node *head=hashtable[i];head!=NULL;head=head->next)
            {
                count++;
            }
        }
        return count;
    }
    //no
    return 0;
}
//lowercase transform
void toStrLower(char *str)
{
    for(int i=0;i<strlen(str);i++)
    {
        if(isupper(str[i]))
        {
            str[i]=tolower(str[i]);
        }
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //transform word to be lowercase
    char wordcopy[LENGTH + 1];
    strcpy(wordcopy,word);
    toStrLower(wordcopy);
    for(node *head=hashtable[hash(wordcopy)];head!=NULL;head=head->next)
    {
        if(!strcmp(wordcopy,head->word))
        {
            //free(wordcopy);
            return true;
        }
    }
    //free(wordcopy);
    return false;
}

//free linklist in hashtable，return true if success(would not return false)
bool freeLList(node * hashTable)
{
    node *head=hashTable;
    if(!head)
        return true;
    else if(!head->next)
    {
        free(head);
        hashTable=NULL;
        return true;
    }
    else
    {
        return freeLList(head->next);
    }

}
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO

    //free memory
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        //free each link list
        bool r=freeLList(hashtable[i]);
        if(r==false)
            return false;
    }
    return true;
}