#include <stdio.h>
#include <string.h>
int main()
{
    char buf[1024];
    memset(buf, '1', sizeof(buf));
    buf[1023] = '\0';
    printf("%s\n", buf);
    ((long *)buf)[0] = 0x04100301;
    printf("%s\n", buf);
    return 0;
}
