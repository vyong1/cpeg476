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
    for(i = 0; i < bytes; i++)
    {
        int letter = i%8;
        if(letter == 0 || letter == 3)
            p2chunk[i] = 'D';
        else if(letter == 1 || letter == 5 || letter == 6)
            p2chunk[i] = 'E';
        else if (letter == 2)
            p2chunk[i] = 'A';
        else if(letter == 4)
            p2chunk[i] = 'B';
        else if(letter == 7)
            p2chunk[i] = 'F';
    }
    
    // memset(p2chunk, 'A', 256);
    free(p2chunk);

    char* p2chunk2 = (char*)calloc(bytes, sizeof(char));
    printf("chunk 2: %s\n", p2chunk2);
    free(p2chunk2);
}