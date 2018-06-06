#include<stdio.h>
#include<string.h>
#include<time.h>
int main()
{
    int i;
    time_t tm;
    char tmp[128] = {0};
    struct mystruct
    {
        char cha;
        char chb;
    }s;
  //  struct mystruct s;
    FILE *fp = NULL;
    char szData[1024] = {0};
    printf("%d\n", sizeof(FILE));
    if((fp = fopen("data.txt", "awb"))==NULL)
    {
        fprintf(stderr, "Cannot open output file.\n");
        return -1;
    }
    tm = time(NULL);
    snprintf(tmp, sizeof(tmp), "start %ld\r\n", tm);
    fwrite(tmp, strlen(tmp), 1, fp);
    for(i = 0; i<100000; i++)
    {
        snprintf(szData, sizeof(szData), "%05d. dont you know who YuriBoyka is?\r\n", i);
        //s.cha = 'A';
        //s.chb = 'B';
        fwrite(szData, strlen(szData), 1, fp);
    }
    tm = time(NULL);
    snprintf(tmp, sizeof(tmp), "end %ld\r\n", tm);
    fwrite(tmp, strlen(tmp), 1, fp);
    fclose(fp);
    return 0;

}
