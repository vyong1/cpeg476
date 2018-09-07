#include "strlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char* tweets[3] = {"a b", "b a", "a c"};

    int arrLen = 0;
    splitStr("ha ha", ' ', &arrLen);
    printf("%d\n", arrLen);
    
    char* test = "HAHA";
    char* lower = (char*)(malloc(strlen(test))); 
    strToLower(test, &lower);
    printf("%s\n", lower);
    
    free(lower);
}