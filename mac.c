#include<stdio.h>
#define MUL(x,y) x*y
#define ADD(x,y) (x+y)
#define SUB(x,y) (x-y)

int main()
{
    int num = MUL(ADD(9,2), SUB(6,3));
    printf("%d\n", num);
    char a[] = "\r\n";
    printf("sizeof a %d\n", sizeof(a));
    char b[] = {0xff, 0xff, 0x00};
    printf("sizeof b %d\n", sizeof(b));
    return 0;
}
