#include <list>
#include <iostream>
using namespace std;
int main()
{
    //list的空间不是连续的，所以删除一个元素后，其余的元素不会发生变化，那么在删除一个元素后就需要对迭代器做加法使其指向下一个元素，或者利用erase的返回值（指向下一个元素的迭代器）。
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
