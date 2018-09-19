#include<stdio.h>
enum {
    one = 1,
    two,
} test;
enum {
    one1 = 1,
    two2,
} test2;
int main()
{
    test = 3;
    printf("%d\n", test);
    return 0;
}
