#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
//从左往右解木板倒水
int main() {
    int n,ans=0;
    cin>>n;
    Stack<Node> stack(n);
    Node temp;
    for(int i=1;i<=n;i++){
        cin>>temp.height;
        temp.id=i;
        //遇到了右侧第一个比栈顶元素大的元素,计算并出栈
        while(!stack.empty()&&stack.top().height<=temp.height){
            ans=ans+i-stack.top().id-1;
            stack.pop();
        }
        stack.push(temp);
    }
    //现在栈中的木板右侧没有比它高的木板,用最右侧无限高的木板减
    while(!stack.empty()){
        ans=ans+n+1-stack.top().id-1;
        stack.pop();
    }
    cout<<ans<<endl;
    return 0;
}
