#include<pthread.h>
#include <stdio.h>
void *fun()
{
    int i;
    for (i = 0; i < 10; i++)
        printf("test fun\n");
}
void *fun2()
{
    int i;
    for (i = 0; i < 10; i++)
        printf("test fun2\n");
}
int main()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, fun, NULL);
    pthread_create(&tid2, NULL, fun2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}
