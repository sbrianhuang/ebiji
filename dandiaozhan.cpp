#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
//�������ҽ�ľ�嵹ˮ
int main() {
    int n,ans=0;
    cin>>n;
    Stack<Node> stack(n);
    Node temp;
    for(int i=1;i<=n;i++){
        cin>>temp.height;
        temp.id=i;
        //�������Ҳ��һ����ջ��Ԫ�ش��Ԫ��,���㲢��ջ
        while(!stack.empty()&&stack.top().height<=temp.height){
            ans=ans+i-stack.top().id-1;
            stack.pop();
        }
        stack.push(temp);
    }
    //����ջ�е�ľ���Ҳ�û�б����ߵ�ľ��,�����Ҳ����޸ߵ�ľ���
    while(!stack.empty()){
        ans=ans+n+1-stack.top().id-1;
        stack.pop();
    }
    cout<<ans<<endl;
    return 0;
}
