#include <stdio.h>
int main()
{
    struct {
        int x;
        struct {
            int y,z;
        } nested;
    } i = {.nested.y = 5, 6, .x = 1, 2, 3};
    printf("------- %d, %d\n", i.nested.y, i.nested.z);
    return 0;
}
