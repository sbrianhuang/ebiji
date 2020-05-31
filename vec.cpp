#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void print(vector<int>);
int main()
{
    int a[6] = {1,2,3,4,5,6};
    vector<int> b(a, a+6);
    for (vector<int>::iterator it = b.begin(); it != b.end(); it++)
    {
        cout <<*it<<endl;
    }
    return 0;
}
