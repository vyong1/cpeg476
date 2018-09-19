int main()
{
    int a;
    int* b;     // b is a pointer

    a = *b;     // a = contents of address at b
    a = b;      // a = address of b
    a = &b;     // a = address of address of b
}