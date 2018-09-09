#include "strlib.h"
#include "markov_structs.h"
#include "markovlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


MarkovNode_t* generateMarkovMap(char* str)
{
    int splitLen;
    char** split = splitStr(str, ' ', &splitLen);

    MarkovNode_t* head = NULL;

    int i;
    for(i = 0; i < splitLen; i++)
    {
        appendMarkovNode(&head, split[i]);
    }

    return head;
}