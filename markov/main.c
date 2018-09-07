#include <stdio.h>
#include "strlib.h"

int main()
{
    char* tweets[2] = {"A", "B"};
    
    int i;
    for(i = 0; i < 2; i++)
    {
        printf("%s\n", tweets[i]);
    }

    int len = 0;
    splitStr("ha ha", ' ', &len);
    printf("%d\n", len);
}