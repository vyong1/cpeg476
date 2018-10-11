#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* this only works on c9.io */
int main(int argc, char **argv) {
    size_t bytes = 256;
    char* p2chunk = (char *)malloc(bytes);
    getline(&p2chunk, &bytes, stdin);
    printf("chunk 1: %s\n", p2chunk);
    
    int i;
    for(i = 0; i < 256; i++)
    {
        int letter = i%8;
        int mask = 0x0000000F;
        p2chunk[i] = ( (0xDEADBEEF) >> (8 - letter) ) & mask;
    }
    printf("%s\n", p2chunk);
    
    free(p2chunk);

    char* p2chunk2 = (char*)malloc(bytes);
    printf("chunk 2: %s\n", p2chunk2);
    free(p2chunk2);
}