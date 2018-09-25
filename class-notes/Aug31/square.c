#include "stdio.h"

int square(int a)
{
    return a * a;
}

int main() {
    int n = 5;
    printf("%d^2 = %d\n", n, square(n));
    return 0;
}