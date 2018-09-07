#include <stdio.h>

int main()
{
    char mystr[5] = "haha\0";
    printf("mystr:              %s\n", mystr);
    printf("address of mystr:   %p\n", (void*)mystr);
    return 0;
}