#include <stdio.h>
int main()
{
    int i = 0;
    char a[10] ="11111cccc1";
    for (i = 1; i<10; i++)
    {
        if(a[i-1]=='c'&&a[i]=='1')
            printf(".......\n");
    }
    return 0;
}
