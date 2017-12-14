#include<stdio.h>
#define Max_ 15
// ��ӡ���
void data_print(int  arr[], int n)
{
    int i;
    for ( i=0; i<n; i++ )
        printf("%d  ", arr[i]);
    printf("\n");
}

// �鲢�����еĺϲ��㷨
void merge(int array[], int left, int m, int right)
{
    int aux[Max_] = {0};  // ��ʱ���� ������ʹ����ʱ���飬��������������ϲ�Ϊһ����������Ƚ��鷳��
    int i; //��һ����������
    int j; //�ڶ�����������
    int k; //��ʱ��������

    for (i = left, j = m+1, k = 0; k <= right-left; k++) // �ֱ� i, j, k ָ�����������ײ���
    {
        //�� i �����һ�������β�������ڶ�����������Ԫ�ظ��Ƶ� ��ʱ������
        if (i == m+1)
        {
            aux[k] = array[j++];
            continue;
        }
        //�� j ����ڶ��������β��������һ����������Ԫ�ظ��Ƶ� ��ʱ������
        if (j == right+1)
        {
            aux[k] = array[i++];
            continue;
        }
        //�����һ������ĵ�ǰԪ�� �� �ڶ�������ĵ�ǰԪ��С���� ��һ������ĵ�ǰԪ�ظ��Ƶ� ��ʱ������
        if (array[i] < array[j])
        {
            aux[k] = array[i++];
        }
        //����ڶ�������ĵ�ǰԪ�� �� ��һ������ĵ�ǰԪ��С���� �ڶ�������ĵ�ǰԪ�ظ��Ƶ� ��ʱ������
        else
        {
            aux[k] = array[j++];
        }
    }

    //���������ʱ���� Ԫ�� ˢ�� ����������� array �У�
    //i = left , �����������array ����ʼλ��
    //j = 0�� ��ʱ�������ʼλ��
    for (i = left, j = 0; i <= right; i++, j++)
    {
        array[i] = aux[j];
    }
}

// �鲢����
void merge_sort(int array[], int start, int end)
{
    if (start < end)
    {
        int i;
        i = (end + start) / 2;
        // ��ǰ�벿�ֽ�������
        merge_sort(array, start, i);
        // �Ժ�벿�ֽ�������
        merge_sort(array, i + 1, end);
        // �ϲ�ǰ��������
        merge(array, start, i, end);
    }
}

int main()
{   //��������
    int arr_test[Max_] = { 8, 4, 2, 3, 5, 1, 6, 9, 0, 7 ,10, 11, 14, 13, 12};
    //����ǰ��������
    data_print( arr_test, Max_ );
    merge_sort( arr_test, 0, Max_-1 );
    //�������������
    data_print( arr_test, Max_ );
    return 0;
}
