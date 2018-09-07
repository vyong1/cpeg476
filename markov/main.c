#include "strlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char* tweets[3] = {"a b", "b a", "a c"};

    int splitLen = 0;
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