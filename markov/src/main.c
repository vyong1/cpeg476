#include "strlib.h"
#include "markov_structs.h"
#include "markovlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void splitStringExample();
void toLowerExample();
void proceedingWordsExample();

int main()
{
    char* word = "I";
    char* sentence = "I praise the lord I break the law I take what's mine I take some more";
    
    MarkovNode_t* head = generateMarkovMap(sentence);
    printMarkovMap(head);
}

void proceedingWordsExample()
{
    char* word = "I";
    char* sentence = "I praise the lord I break the law I take what's mine I take some more";
    
    int proceedingLen;
    char** proceeding = getAllProceedingWords(word, &proceedingLen, sentence);

    // Print and free
    int i;
    for(i = 0; i < proceedingLen; i++)
    {
        printf("%s\n", proceeding[i]);
        free(proceeding[i]);
    }
    free(proceeding);
}

void splitStringExample()
{
    int splitLen;
    char** split = splitStr("this is a test of the national broadcasting service", ' ', &splitLen);
    
    int i;
    for(i = 0; i < splitLen; i++)
    {
        printf("%s\n", split[i]);
    }

    freeSplitArr(split, splitLen);
}

void toLowerExample()
{
    char* test = "HAHA";
    char* lower = (char*)(malloc(strlen(test))); 
    strToLower(test, &lower);
    printf("%s\n", lower);
    free(lower);
}