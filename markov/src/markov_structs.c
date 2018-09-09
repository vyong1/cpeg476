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
        printf("Empty\n");
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

void printMarkovNode(MarkovNode_t* node)
{
    printf("Markov Node\n");
    printf("{\n");
    printf("\tWord:     %s\n", node->word);
    printf("\tPairs:    %d\n", node->totalPairs);
    printf("\tFreqList: ");
    printWordFreqList(node->freqHead);
    printf("}\n");
}

void printMarkovMap(MarkovNode_t* head)
{
    if(head == NULL)
    {
        printf("The map is empty.\n");
        return;
    }

    MarkovNode_t* current = head;

    while(current != NULL)
    {
        printMarkovNode(current);
        current = current->next;
    }

    printf("\n");
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

MarkovNode_t* newMarkovNode(MarkovNode_t* next, char* word, int totalPairs, WordFreqNode_t* head)
{
    MarkovNode_t* nodeptr = (MarkovNode_t*)malloc(sizeof(MarkovNode_t));

    nodeptr->next = next;
    nodeptr->word = word;
    nodeptr->totalPairs = totalPairs;
    nodeptr->freqHead = head;
    
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
void appendWord(WordFreqNode_t** head, char* word)
{
    if((*head) == NULL)
    {
        (*head) = newWordFreqNode(NULL, word, 1);
        return;
    }

    WordFreqNode_t* current = *head;

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


void appendMarkovNode(MarkovNode_t** head, char* markovWord)
{
    MarkovNode_t* current = *head;

    if((*head) == NULL)
    {
        (*head) = newMarkovNode(NULL, markovWord, 0, NULL);
        return;
    }

    while(current->next != NULL)
    {
        // If the word was already found in the "map",
        // then don't append it as a node
        if(strcmp(markovWord, current->word) == 0)
        {
            return;
        }

        current = current->next;
    }

    // Check the last node
    if(strcmp(markovWord, current->word) == 0)
    {
        return;
    }

    // Word not found -> make a new node
    current->next = newMarkovNode(NULL, markovWord, 0, NULL);
}