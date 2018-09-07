#include "strlib.h"
#include <stdio.h>
#include <string.h>

char** splitStr(char* str, char delimiter, int* lenPtr)
{
    // Count the number of delimiters
    int i;
    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] == delimiter)
        {
            (*lenPtr)++;
        }
    }

    printf("%d\n", *lenPtr);

}