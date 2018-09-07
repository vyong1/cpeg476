#include "strlib.h"
#include "markov_structs.h"
#include "markovlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void splitStringExample();
void toLowerExample();

int main()
{
    int a = countWordFreq("the", "this ice cream is the best of the worst the the the");
    printf("%d\n", a);

    WordFreqNode_t* n3 = newWordFreqNode(NULL, "ice", countWordFreq("ice", "this ice cream is the best of the worst the the the"));
    WordFreqNode_t* n2 = newWordFreqNode(n3, "best", countWordFreq("best", "this ice cream is the best of the worst the the the"));
    WordFreqNode_t* n1 = newWordFreqNode(n2, "the", countWordFreq("the", "this ice cream is the best of the worst the the the"));

    printWordFreqList(n1);
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