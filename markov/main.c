#include <stdio.h>
#include "strlib.h"

int main()
{
    char* tweets[3] = {"a b", "b a", "a c"};
    
    int i;
    for(i = 0; i < 3; i++)
    {
        printf("%s\n", tweets[i]);
    }

    int len = 0;
    splitStr("ha ha", ' ', &len);
    printf("%d\n", len);
    
    char* test = "HAHA";
    strToLower(&test);
    printf("%s\n", test);
}