#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main(int argc,char *argv[])/*��������������*/
{
pid_t pid=fork();/*���ݲ���*/
if(pid<0)/*���(���̱��<0)*/
{
fprintf(stderr,"����");
}
else if(pid==0)/*�������(���̱��==0)*/
{
printf("�ٶȰٿƣ������ӽ��̣�");
exit(0);
}
else/*����*/{
printf("�ٶȰٿƣ����Ǹ����̣��ӽ��̵Ľ��̱��Ϊ=%d",pid);
}
//������Ҫʱ��wait��waitpid�����ȴ��ӽ��̵Ľ�������ȡ����״̬
exit(0);
}
