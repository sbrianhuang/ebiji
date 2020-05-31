#include <stdio.h>
#include <vector>

using namespace std;
bool used[10];
vector <long long> v;
void dfs(int k, long long a)
{
    if(k&&a%k!=0)
        return;
    if (k == 9)
    {
        v.push_back(a);
        return;
    }
    for (int i = 1; i <= 9; i++)
        if (!used[i])
        {
            used[i] = 1;
            dfs(k+1, a*10+i);
            used[i] = 0;
        }
}
int main()
{
    dfs(0,0);
    for(int i = 0; i < v.size(); i++)
        printf("%lld ", v[i]);
    getchar();
}
