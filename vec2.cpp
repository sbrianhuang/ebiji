#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int a[] = {1,4,3,7,9,3,6,8,3,3,5,2,3,7};
    vector<int> vi(a, a+sizeof(a)/sizeof(int));

    cout<<"---before delete-----"<<endl;
    for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        cout <<*it<<" ";
    }
    cout<<endl;

    for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        //ectorʹ��eraseɾ��Ԫ�أ��䷵��ֵָ����һ��Ԫ�أ���������vector��������ʣ�����һ���������ڴ��ϣ���ɾ��һ��Ԫ�غ�����Ԫ�ض�����ǰ�ƶ������Դ�ʱָ����һ��Ԫ�صĵ�������ʵ���ոձ�ɾ��Ԫ�صĵ�������һ���ġ�
        if(*it == 3)
        {
            vi.erase(it);
            it--;
        }

    }
    cout<<"---after delete-----"<<endl;
    for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        cout <<*it<<" ";
    }
    cout<<endl;
    return 0;
}
