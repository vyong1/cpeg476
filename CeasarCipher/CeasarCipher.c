#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

char* translate(char* encodedMessage);
char* readInputFile();
char rot13_char(char c);
char rot13_int(int c_ind);
int alphabetIndexOf(char c);

const char alphabet[ALPHABET_SIZE] = 
    {   
        'a',
        'b',
        'c',
        'd',
        'e',
        'f',
        'g',
        'h',
        'i',
        'j',
        'k',
        'l',
        'm',
        'n',
        'o',
        'p',
        'q',
        'r',
        's',
        't',
        'u',
        'v',
        'w',
        'x',
        'y',
        'z'
    };

int main(void) 
{
    char* input = readInputFile();

    char* translated = translate(input);

    printf("%s\n", translated);

    return 0;
}

/* Translates numbers from a ROT13 message */
char* translate(char* encodedMessage)
{
    int len = strlen(encodedMessage);
    char* translated = (char*)malloc(len);
    char* digit_str = (char*)malloc(3);
    digit_str[2] = '\0';

    int i;
    int j = 0;
    for(i = 0; i < len; i++)
    {
        if(encodedMessage[i] == '-')
        {
            // Insert nothing
        }
        else if(encodedMessage[i] == ' ')
        {
            translated[j] = ' ';
            j++;
        }
        else /* A number */
        {
            int num;
            if(i + 1 < len)
            {
                // 2 digit number
                if(encodedMessage[i + 1] != '-' && encodedMessage[i + 1] != ' ')
                {
                    digit_str[0] = encodedMessage[i];
                    digit_str[1] = encodedMessage[i + 1];
                    num = atoi(digit_str);
                    i++;
                }
                // 1 digit number
                else
                {
                    digit_str[0] = '0';
                    digit_str[1] = encodedMessage[i];
                    num = atoi(digit_str);
                }
            }
            // 1 digit number
            else
            {
                digit_str[0] = '0';
                digit_str[1] = encodedMessage[i];
                num = atoi(digit_str);
            }
            
            translated[j] = rot13_int(num);
            j++;
        }
    }

    return translated;
}

/* Reads in an input file for the ROT13 encoded message */
char* readInputFile()
{
    // TODO - this doesn't work

    // FILE *fptr;
    // char buffer[5];

    // fptr = fopen("input.text", "r");

    // char c;
    // while(1)
    // {
    //     printf("Hi");
    //     c = fgetc(fptr);
    //     if(c==EOF)
    //         break;
    //     else
    //         printf("%c", 'h');
    // }

    // fclose(fptr);
    return "7-21-22-6 22-6 18-1-16-2-17-18-17 10-22-7-21 14 16-14-18-6-14-5 16-22-3-21-18-5";
}

/* Decode a ROT13 char */
char rot13_char(char c)
{
    return rot13_int(alphabetIndexOf(c));
}

/* 
   Decode a ROT13 integer representation of a letter
   (i.e. the letter's position in the alphabet)
 */
char rot13_int(int c_ind)
{
    return alphabet[(c_ind + 12)%ALPHABET_SIZE];
}

/* Finds the index of a character in the alphabet array */
int alphabetIndexOf(char c)
{
    /*
        strchr(alphabet, c) returns the pointer to c in alphabet.
        Subtracting &alphabet[0] returns the index of c in alphabet.
    */
    return (strchr(alphabet, c) - &alphabet[0]);
}