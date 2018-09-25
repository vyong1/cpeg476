/*
    Splits a string by a delimiter. Returns the split
    array, and assigns the number of elements in that
    array to lenPtr.
*/
char** splitStr(char* str, char delimiter, int* lenPtr);

/*
    Free a malloc'd split string array
*/
void freeSplitArr(char** splitArr, int splitLen);

/*
    Assigns a lowercase version of str to outLower
*/
void strToLower(char* str, char** outLower);

/*
    Returns the count of word in str.
    Case sensitive.
*/
int countWordFreq(char* word, char* str);

/*
    Gets all the immediately proceeding words to a word
    in a split string
*/
char** getAllProceedingWords(char* word, int* lenPtr, char* sentence);