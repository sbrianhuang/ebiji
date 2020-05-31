#include <iostream>
#include <vector>
using namespace std;
int sum(vector<int> vec)
{
    int result = 0;
    vector<int>::iterator p = vec.begin();
    while(p!=vec.end())
    {
        result += *p++;
    }
    return result;
}
int count(vector<int> vec)
{
    int count = 0;
    vector<int>::iterator it = vec.begin();
    while(it != vec.end())
    {
        count++;
        it++;
    }
    cout<<count<<endl;
}

int main()
{
    vector<int> v1(10);
    cout << v1.size()<<endl;
    cout<<sum(v1)<<endl;
    v1.push_back(23);
    cout<<v1.size()<<endl;
    cout<<sum(v1)<<endl;
    cout<<v1[0]<<" "<<v1[100]<<endl;
    cout<<"111111111111"<<endl;
    v1.reserve(20);
    count(v1);
    cout<<"22222222222222"<<endl;
    cout<<v1.size()<<endl;
    v1[13]=13;
    cout<<v1.size()<<endl;
    cout<<v1[13]<<endl;
    cout <<v1.front()<<endl;
    cout <<v1.back()<<endl;
    v1.pop_back();
    cout<<v1.back()<<endl;

    return 0;
}
