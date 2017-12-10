#include <stdio.h>
#include <math.h>
#define MAX 9
int temp[MAX];   //记录每次选的数的位数
int number[MAX]={1,2,3,4,5,6,7,8,9};
int relNum[MAX];   //记录每次选的数的数

void fun(int index,int num)      //递归到第几层了
{
    int i,j,z,   //第几个相加的数下标
        x,  //数分成的个数
        sum;
    if(index>=MAX)
    {
        z=0;
        for(i=0;i<9;)
        {
            sum=0;
            for(j=0;j<temp[z];j++)
            {
                sum+=number[i+j]*pow(10,temp[z]-1-j);    //每个数给算出来
            }
            relNum[z]=sum;
            z++;
            i+=j;
        }
        x=pow(2,num);
        for(j=0;j<x;j++)
        {
            sum=0;
            for(i=0;i<num;i++)
            {
                if(i==0||j&(1<<i))
                {
                   sum+=relNum[i];
                }
                else
                {
                   sum-=relNum[i];
                }
            }
            /************输出结果*********/
            if(sum==100
                &&j&1)   //判断第一个符号（1之前的）是否为+
            {
              for(i=0;i<num;i++)
              {
                 if(i==0||j&(1<<i))
                 {
                    if(i==0)
                        printf("%3d",relNum[i]);
                    else
                        printf(" +%3d",relNum[i]);
                 }
                 else
                 {
                    printf(" -%3d",relNum[i]);
                 }

              }
                printf("=%4d\n",sum);    //输出和
            }
        }
    }
    else
    {
        for(i=1;i<=3;i++)
        {
            temp[num]=i;
            if(index+i>9)
                break;
            fun(index+i,num+1);
        }
    }
}

int main()
{
    fun(0,0);
    return 0;
}
