#include <stdio.h>
int del(int x, int y)
{
    return x-y;
}
int divide(int x, int y)
{
    return x/y;
}
void test(int (*p)(int, int), int a, int b)
{
    int int1;
    int1 = (*p)(a,b);
    printf("a=%d, b=%d, result = %d\n", a, b, int1);
}
int main()
{
    int a=1, b=9;
    test(del, a, b);
    test(divide, a, b);
    return 0;
}
