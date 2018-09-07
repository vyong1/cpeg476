#include "strlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** splitStr(char* str, char delimiter, int* arrLenPtr)
{
    // Count the number of delimiters
    int i;
    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] == delimiter)
        {
            (*arrLenPtr)++;
        }
    }

    // TODO - split the string
}

void strReplace(char* str, char toReplace)
{

}

void* strToLower(char* str, char** outLower)
{
    int len = strlen(str);

    int i;
    for(i = 0; i < len; i++)
    {
        (*outLower)[i] = tolower(str[i]);
    }
}