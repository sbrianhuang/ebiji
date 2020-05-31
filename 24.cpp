#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

/* ��Ž⼯ */
vector<string> ivec;

/* ��1�����͵�2������ֵ�����ʽ */
double key1_2[6] = {0};
string exp1_2[6];

/* ��3�����͵�4������ֵ�����ʽ */
double key3_4[6] = {0};
string exp3_4[6];

/* ��3������ǰ2������ֵ�����ʽ */
double key12_3[6] = {0};
string exp12_3[6];

/* ��4������ǰ3������ֵ�����ʽ */
double key123_4[6] = {0};
string exp123_4[6];

/* ǰ2�����ͺ�2������ֵ�����ʽ */
double key12_34[6] = {0};
string exp12_34[6];

/* �������� */
int Permutation(int[], int[][4]);
void Calc(double, double, double[], string[], string, string);
void Work(int[], int[][4], int);

/* ������ */
int main()
{
    int num[4] = {0};
    int array[24][4] = {0};
    int count = 0;

    /* �������� */
    while(1)
    {
        cout << "������4��1-13֮����������м��Կո����" << endl;
        for (int i = 0; i < 4; i++)
        {
            cin >> num[i];
        }
        /* ��������ݵ����� */
        //cout<<num[0] << num[1] <<num[2] <<num[3]<<endl;
        memset(array, 0, sizeof(array));
        count = Permutation(num, array);
        /* ���24�� */
        Work(num, array, 24);

        /* �Խ���������� */
        sort(ivec.begin(), ivec.end());

        /* ȥ���ظ��Ľ� */
        vector<string>::iterator iter = unique(ivec.begin(), ivec.end());

        /* ����⼯ */
        //cout << ivec.size()<<endl;
        if (0 != ivec.size())
        {
            cout << "�������ݵĽ�Ϊ:" << endl;
            for (vector<string>::iterator it = ivec.begin(); it != iter; it++)
            {
                cout << *it << endl;
            }

        }
        else
        {
            cout << "���������޽�" << endl;
        }
        ivec.clear();
        //cout<<"1111111111 "<<ivec.size()<<endl;
    }
    system("pause");
    return 0;
}

/* ����2����������ֵ�����ʽ */
void Calc(double a, double b, double key[], string exp[], string expa, string expb)
{
    key[0] = a + b;
    exp[0] = '(' + expa + '+' + expb + ')';

    key[1] = a - b;
    exp[1] = '(' + expa + '-' + expb + ')';

    key[2] = b - a;
    exp[2] = '(' + expb + '-' + expa + ')';

    key[3] = a * b;
    exp[3] = '(' + expa + '*' + expb + ')';

    if (b > 0)
    {
        key[4] = a / b;
        exp[4] = '(' + expa + '/' + expb + ')';
    }

    if (a > 0)
    {
        key[5] = b / a;
        exp[5] = '(' + expb + '/' + expa + ')';
    }
}

/* �������ݵ�������� */
int Permutation(int num[], int array[][4])
{
    int flag;
    int k = 0;
    int count = 0;
    int i, j, m, n, s;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (m = 0; m < 4; m++)
            {
                for (n = 0; n < 4; n++)
                {
                    if (i != j && i != m && i != n && j != m && j != n && m != n)
                    {
                        flag = 1;
                        for(s = 0; s < k; s++)
                        {
                            if(array[s][0] == num[i] && array[s][1] == num[j] && array[s][2] == num[m] && array[s][3] == num[n])
                            {
                                flag = 0;
                            }
                        }
                        if (flag == 1)
                        {
                            array[k][0] = num[i];
                            array[k][1] = num[j];
                            array[k][2] = num[m];
                            array[k][3] = num[n];
                            k++;
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}

/* ���24�� */
void Work(int num[], int array[][4], int count)
{
    for (int i = 0; i < count; i++)
    {
        char buffer[20];
        string expa, expb;

        /* ת����1������Ϊ���ʽ */
        itoa(array[i][0], buffer, 10);
        expa = buffer;

        /* ת����2������Ϊ���ʽ */
        itoa(array[i][1], buffer, 10);
        expb = buffer;

        /* �����1�����͵�2���� */
        Calc(array[i][0], array[i][1], key1_2, exp1_2, expa, expb);

        /* (((A,B),C),D)��ʽ */
        for (int j = 0; j < 6; j++)
        {
            /* ת����3������Ϊ���ʽ */
            itoa(array[i][2], buffer, 10);
            expb = buffer;

            /* �����3������ǰ2���� */
            Calc(key1_2[j], array[i][2], key12_3, exp12_3, exp1_2[j], expb);

            for (int k = 0; k < 6; k++)
            {
                /* ת����4������Ϊ���ʽ */
                itoa(array[i][3], buffer, 10);
                expb = buffer;

                /* �����4������ǰ3���� */
                Calc(key12_3[k], array[i][3], key123_4, exp123_4, exp12_3[k], expb);

                for (int t = 0; t < 6; t++)
                {
                    if (fabs(key123_4[t] - 24) < 1e-6)
                    {
                        ivec.push_back(exp123_4[t]);
                    }
                }
            }
        }

        /* ת����3������Ϊ���ʽ */
        itoa(array[i][2], buffer, 10);
        expa = buffer;

        /* ת����4������Ϊ���ʽ */
        itoa(array[i][3], buffer, 10);
        expb = buffer;

        /* �����3�����͵�4���� */
        Calc(array[i][2], array[i][3], key3_4, exp3_4, expa, expb);

        /* ((A,B),(C,D))��ʽ */
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                /* ����ǰ2�����ͺ�2���� */
                Calc(key1_2[j], key3_4[k], key12_34, exp12_34, exp1_2[j], exp3_4[k]);

                for (int t = 0; t < 6; t++)
                {
                    if (fabs(key12_34[t] - 24) < 1e-6)
                    {
                        ivec.push_back(exp12_34[t]);
                    }
                }
            }
        }
    }
}
