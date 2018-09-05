#include "stdio.h"
#include "string.h"

int main(void) {
  char text[128] = "Andy is the greatest";
  //Old fashioned C strings
  //char is a one byte integer type used to store an ASCII character
  // char text[128] declares an array of 'char's and = "..." initializes the values stored in that array
  // after the "t" in greatest there will be stored a null byte (00000000) to indicate the end of the character array
  int len = strlen(text);
  printf("Length: %d\n", len);

  printf("%s\n", text);
  //The format flag %s will print out the entire character array as text
  //this is the old fashioned version of a "string"
  return 0;
}