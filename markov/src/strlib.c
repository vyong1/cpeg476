#include "strlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char** splitStr(char* str, char delimiter, int* arrLenPtr)
{
    // Count the number of delimiters
    (*arrLenPtr) = 0;
    int i;
    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] == delimiter)
        {
            (*arrLenPtr)++;
        }
    }
    // # of words = # of delimiters + 1
    (*arrLenPtr)++;
    int len = (*arrLenPtr);

    // Dynamically allocate memory for a char* array
    char** strArr = (char**)(malloc(len * sizeof(char*)));
    for(i = 0; i < len; i++)
    {
        strArr[i] = (char*)(malloc(sizeof(char*)));
    }

    char buffer[128];
    i = 0;      // Keeps track of the location in the original string
    int j = 0;  // Keeps track of the string we are on
    int k = 0;  // Keeps track of the location in the buffer
    for(i = 0; i < strlen(str); i++)
    {
        // Empty buffer into strArr[j]
        if(str[i] == delimiter)
        {
            buffer[k] = '\0';
            strcpy(strArr[j], buffer);
            buffer[0] = '\0'; // Clear the buffer
            j++;
            k = 0;
        }
        // Build up the buffer
        else
        {
            buffer[k] = str[i];
            k++;
        }
    }
    // Empty the buffer for the last word
    buffer[k] = '\0';
    strcpy(strArr[j], buffer);

    return strArr;
}

void freeSplitArr(char** splitArr, int splitLen)
{
    int i;
    for(i = 0; i < splitLen; i++)
    {
        free(splitArr[i]);
    }
    free(splitArr);
}

void strToLower(char* str, char** outLower)
{
    int len = strlen(str);

    int i;
    for(i = 0; i < len; i++)
    {
        (*outLower)[i] = tolower(str[i]);
    }
}