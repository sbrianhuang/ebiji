#include <list>
#include <iostream>
using namespace std;
int main()
{
    //list�Ŀռ䲻�������ģ�����ɾ��һ��Ԫ�غ������Ԫ�ز��ᷢ���仯����ô��ɾ��һ��Ԫ�غ����Ҫ�Ե��������ӷ�ʹ��ָ����һ��Ԫ�أ���������erase�ķ���ֵ��ָ����һ��Ԫ�صĵ���������
    int a[] = {1,4,3,7,9,3,6,8,3,3,5,2,3,7};
    iist<int> list_int(a, a+sizeof(a)/sizeof(int));

    list<int>:: iterator l = list_int.begin();
    while(l != list_int.end())
    {
        if(*l == 3)
        {
            list_int.erase(l++);
            // cout << *l << endl;
        }
        else
        {
            l++;
        }
    }

    for(list<int>::iterator itor = list_int.begin(); itor != list_int.end(); itor++)
    {
        cout << * itor << "  ";
    }
    cout << endl;
}
