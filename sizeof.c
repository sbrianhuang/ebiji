#include <stdio.h>
void foo()
{
    static int a = 10;
    a = a * 2;
    printf("----%d\n", a);
}
int main()
{
    foo();
    printf("aaaaaa\n");
    foo();
    printf("bbbbbb\n");
    foo();
    return 0;
}
