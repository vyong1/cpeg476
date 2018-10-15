#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "strlcpy.c"
#include "strlcat.c"

/*
    strlcpy (OpenBSD's solution, guarantees a NULL character at the end of each string)
    strlcat
    strcpy_s (Annex K's solution, meant to drop into legacy code)
    strcat_s
    strncpy_s
    strncat_s
*/


void lcpy(char *data) 
{
    char name[64];
    strlcpy(name, data, 64);
    printf("%s\n", name);
}

void lcat(char* data)
{
    char* name = (char*)(malloc(64*sizeof(char)));
    name[0] = 'h';

    strlcat(name, data, 64);
    printf("%s\n", name);
}

void realloc(char* data)
{
    char* mydata = (char*)(malloc(2*sizeof(char)));
    realloc(mydata, strlen(data) + 1);
    strcpy(mydata, data);
}

int main(int argc, char **argv) 
{
    lcpy(argv[1]);
}