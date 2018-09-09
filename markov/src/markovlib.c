#include "strlib.h"
#include "markov_structs.h"
#include "markovlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


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