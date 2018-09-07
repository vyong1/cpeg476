#include "strlib.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

void strToLower(char** strptr)
{
    int len = strlen(*strptr);

    int i;
    for(i = 0; i < len; i++)
    {
        printf("%c\n", tolower((*strptr)[i]));

        // (*strptr)[i] = tolower((*strptr)[i]);
    }
}