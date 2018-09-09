#include "strlib.h"
#include "markov_structs.h"
#include "markovlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>


MarkovNode_t* generateMarkovMap(char* sentence)
{
    int splitLen;
    char** split = splitStr(sentence, ' ', &splitLen);

    MarkovNode_t* head = NULL;

    int i;
    for(i = 0; i < splitLen; i++)
    {
        appendMarkovNode(&head, split[i]);
    }

    // Measure all the frequencies
    MarkovNode_t* current = head;

    while(current != NULL)
    {
        int proceedingLen;
        char** proceedingWords = 
            getAllProceedingWords(current->word, &proceedingLen, sentence);

        for(i = 0; i < proceedingLen; i++)
        {
            appendWord(&(current->freqHead), proceedingWords[i]);
        }
        
        current->totalPairs = proceedingLen;
        current = current->next;
    }

    return head;
}


char* getNextWord(MarkovNode_t* head, char* word)
{
    // Find the node with "word"
    MarkovNode_t* current = head;

    while(current != NULL)
    {
        if(strcmp(current->word, word) == 0)
        {
            break;
        }

        current = current->next;
    }
    
    if(current == NULL)
    {
        return "Error - word not found";
    }

    // Extract the word based on the randomly
    // generated number and the frequency
    int selected = rand()%(current->totalPairs) + 1;
    // printf("%d\n", selected);

    WordFreqNode_t* freqCurrent = current->freqHead;

    int freqSum = 0;
    while(freqCurrent != NULL)
    {
        freqSum = freqSum + freqCurrent->freq;

        if(freqCurrent->next != NULL)
        {
            if(selected == freqSum || freqSum > selected)
            {
                return freqCurrent->word;
            }
        }
        // At the last node, assume it's the word chosen
        else
        {
            return freqCurrent->word;
        }

        freqCurrent = freqCurrent->next;
    }

    if(freqCurrent == NULL)
    {
        return " ";
    }
}