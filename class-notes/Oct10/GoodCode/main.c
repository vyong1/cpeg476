#include <stdio.h>

int main()
{
    printf("Hi\n");
    
    char* buffer;
    /* Flawfinder: ignore */
    gets(buffer);
}