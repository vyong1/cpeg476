#include "stdio.h"

int main() {
  int i = 0;
  for(;;)
  {
    if(i == 5)
    {
        break;
    }

    printf("i = %d\n",i++);
  }

  return 0;
}