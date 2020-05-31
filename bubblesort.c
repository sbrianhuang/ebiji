#include<stdio.h>
void bubbleSort(int num[], int len)
{
    int flag = 0;
    int i =0,j=0, tmp = 0;
    for(i = 0; i < len-1; i++)// len -1 ´Î
    {
        flag = 0;
        for(j = len-1; j>=i+1 ; j--)
        {
            if(num[j]<num[j-1])
            {
                tmp = num[j];
                num[j] = num[j-1];
                num[j-1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}
int main()
{
    int array[10] = {1,9,2,4,0,5,3,7,6,8};
    bubbleSort(array, sizeof(array)/sizeof(int));
    int i = 0;
    for(i=0; i<10; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}
