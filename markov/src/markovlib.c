#include "strlib.h"
#include "markov_structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


int countWordFreq(char* word, char* str)
{
    int strLen = strlen(str);
    int wordLen = strlen(word);
    int count = 0;

    int i;
    int j;
    bool wordMatch = true;

    // Iterate through str
    for(i = 0; i < strLen; i++)
    {
        // From each character in str, move over the next wordLen chars
        for(j = 0; j < wordLen; j++)
        {
            // If char mismatch,
            if(str[i + j] != word[j])
            {
                wordMatch = false;
                break;
            }
        }

        if(wordMatch == true)
        {
            count++;
        }

        // Reset the flag
        wordMatch = true;
    }

    return count;
}