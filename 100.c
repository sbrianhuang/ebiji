#include <stdio.h>
#include <math.h>
#define MAX 9
int temp[MAX];   //��¼ÿ��ѡ������λ��
int number[MAX]={1,2,3,4,5,6,7,8,9};
int relNum[MAX];   //��¼ÿ��ѡ��������

void fun(int index,int num)      //�ݹ鵽�ڼ�����
{
    int i,j,z,   //�ڼ�����ӵ����±�
        x,  //���ֳɵĸ���
        sum;
    if(index>=MAX)
    {
        z=0;
        for(i=0;i<9;)
        {
            sum=0;
            for(j=0;j<temp[z];j++)
            {
                sum+=number[i+j]*pow(10,temp[z]-1-j);    //ÿ�����������
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
            /************������*********/
            if(sum==100
                &&j&1)   //�жϵ�һ�����ţ�1֮ǰ�ģ��Ƿ�Ϊ+
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
                printf("=%4d\n",sum);    //�����
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
