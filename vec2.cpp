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
        //ector使用erase删除元素，其返回值指向下一个元素，但是由于vector本身的性质（存在一块连续的内存上），删掉一个元素后，其后的元素都会向前移动，所以此时指向下一个元素的迭代器其实跟刚刚被删除元素的迭代器是一样的。
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
