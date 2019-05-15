// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27

// Represents a node in a trie
typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;

// Represents a trie
node *root;


//
node * init_node(void)
{
    node * temp = malloc(sizeof(node));
    if (temp == NULL)
    {
        return false;
    }
    temp->is_word = false;
    for (int i = 0; i < N; i++)
    {
        temp->children[i] = NULL;
    }
    return temp;
}
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize trie
    /*
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return false;
    }
    root->is_word = false;
    for (int i = 0; i < N; i++)
    {
        root->children[i] = NULL;
    }
    */
    root=init_node();

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        node *curser=root;
        //for every character in word
        for(int i=0;word[i]!='\0';i++)
        {
            //find its cell
            //check if it is null
            char temp=tolower(word[i]);
            int index;
            if(temp=='\'')
                index=26;
            else
                index=temp-'a';
           //debug
           /*
            if(index<27)
                printf("index:%d\n",index);
            else
                printf("error\n");
            */
            if((curser->children[index])==NULL)
            {
             //yes
                //for the cell  malloc memory of node
               /*
                node* new=malloc(sizeof(node));
                if(!new)
                {
                    unload();
                    return false;
                }
                */
                node* new=init_node();
                curser->children[index]=new;
            }
            curser=curser->children[index];
            //check if it is the last char
            if(i==strlen(word)-1)
            {
            //yes
                //set cell->is_word=true
                curser->is_word=true;
            }
        }

    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

int count(node *head)
{
    int result=0;
    //every children caculate size
    for(int i=0;i<N;i++)
    {
    //if head->children[i]!=NULL
        node *cursor=head;
        if(cursor->children[i])
        {
            //head=head->children
            cursor=cursor->children[i];
            //if head->is_word==yes
            if(cursor->is_word)
            {
                //count++
                result++;
            }
             //count=count+count(head)
            result+=count(cursor);
        }
    }
    //return count
    return result;
}
//Return true if loaded,else false
bool isloaded(void)
{
    for (int i = 0; i < N; i++)
    {
        if(root->children[i])
            return true;
    }
    return false;
}
// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    //head=root
    node *head=root;
    //if loaded return count();
    if(isloaded())
        return count(head);
    //else return 0
    return 0;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //prepare cursor
    node *head=root;
    //repeatedly check each character in word
    for(int i=0;i<strlen(word);i++)
    {
        //caculate index
        int index;
        char temp=tolower(word[i]);
        if (temp=='\'')
            index=26;
        else
            index=temp-'a';
       //debug
        //printf("index2:%d\n",index);
        //printf("word[%d]:%c\n",index,word[i]);

        //check word
        if(!head->children[index])
            return false;
        else
        {
            head=head->children[index];
            //check if it is the last character in word
            if(i==strlen(word)-1)
            {
            //yes
                return head->is_word;
            }
        }
    }
    return false;
}

//release memory,return true
bool release(node *head)
{
    node *curser=head;
    for(int i=0;i<N;i++)
    {
        if(curser->children[i])
            release(curser->children[i]);
    }
    free(curser);
    return true;
}
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node*head=root;
    return release(head);
}