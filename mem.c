#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
    int n;
    if (0)
    {
        scanf("%d", &n);
        char b[n];
        strcpy(b, "hello");
        printf("%s\n", b);
    }
    else{
        scanf("%d", &n);
        char *a=malloc(n);
                strcpy(a, "hello");
        printf("%s\n", a);
    }
    return 0;
}
