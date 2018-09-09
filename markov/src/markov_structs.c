#include "markov_structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==== Prints
void printWordFreqNode(WordFreqNode_t* node)
{
    printf("[ \"%s\" | %d ]-> ", node->word, node->freq);
    fflush(stdout);
}

void printWordFreqList(WordFreqNode_t* head)
{
    if(head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    WordFreqNode_t* current = head;

    while(current != NULL)
    {
        printWordFreqNode(current);
        current = current->next;
    }

    printf("\n");
}

void printMarkovNode(MarkovNode_t* head)
{
    // TODO
}

// ==== Frees
void freeWordFreqLLNode(WordFreqNode_t* node)
{
    // TODO
}

void freeWordFreqList(WordFreqNode_t* node)
{
    // TODO
}

void freeMarkovNode(MarkovNode_t* node)
{
    // TODO
}

// ==== Constructors
WordFreqNode_t* newWordFreqNode(WordFreqNode_t* next, char* word, int freq)
{
    WordFreqNode_t* nodeptr = (WordFreqNode_t*)malloc(sizeof(WordFreqNode_t));

    nodeptr->next = next;
    nodeptr->word = word;
    nodeptr->freq = freq;
    
    return nodeptr;
}

MarkovNode_t* newMarkovNode(char* word, int totalPairs, WordFreqNode_t* head)
{
    MarkovNode_t* nodeptr = (MarkovNode_t*)malloc(sizeof(MarkovNode_t));

    nodeptr->word = word;
    nodeptr->totalPairs = totalPairs;
    nodeptr->head = head;
    
    return nodeptr;
}

// ==== Append
void append(WordFreqNode_t* head, WordFreqNode_t* toAppend)
{
    WordFreqNode_t* current = head;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = toAppend;
}

// This special append makes a new node if the word isn't in the list
void appendWord(WordFreqNode_t* head, char* word)
{
    WordFreqNode_t* current = head;

    while(current->next != NULL)
    {
        // Word found in the list already - increment the freq
        if(strcmp(word, current->word) == 0)
        {
            current->freq = current->freq + 1;
            return;
        }

        current = current->next;
    }

    // Check the last node
    if(strcmp(word, current->word) == 0)
    {
        current->freq = current->freq + 1;
        return;
    }

    // Word not found -> make a new node
    current->next = newWordFreqNode(NULL, word, 1);
}