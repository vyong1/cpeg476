#include "strlib.h"
#include "markov_structs.h"
#include "markovlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void splitStringExample();
void toLowerExample();
void proceedingWordsExample();

int main()
{
    // Seed the random generator with the current time
    srand(time(0));

    char* word = "I";
    char* sentence = "hi im todd";

    MarkovNode_t* head = generateMarkovMap(sentence);
    printMarkovMap(head);

    int i;
    int saw = 0;
    int came = 0;
    int brk = 0;
    int praise = 0;
    for(i = 0; i < 1000; i++)
    {
        char* nextWord = getNextWord(head, "I");
        // printf("%s\n", nextWord);

        if(strcmp(nextWord, "saw") == 0)
            saw++;
        else if(strcmp(nextWord, "came") == 0)
            came++;
        else if(strcmp(nextWord, "break") == 0)
            brk++;
        else if(strcmp(nextWord, "praise") == 0)
            praise++;
    }
    printf("Saw: %d\nCame: %d\nPraise: %d\nBreak: %d\n", saw, came, praise, brk);
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