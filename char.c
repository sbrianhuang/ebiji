#include <stdio.h>
#include <string.h>
int main()
{
    char *p = "aaaaaaaaaa";
    strcpy(p, "bbb");
    printf("%s\n", p);
    return 0;
}
