#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

//类
class List
{
public:
    //构造器初始化，生成头节点
    List()
    {
        head = new Node;
        head->next=NULL;
    }

    //成员函数
    void createList();
    void insertList(int data);
    void travelList();
    void input();
    int  addNode();
    void deleteData(int addNum);
    void ifClear();
    void clearList();
private:
    //数据成员
    struct Node
    {
        int data; //数据域
        struct Node * next; //指针域

    } * head;//头指针

    int num;//链表元素个数
};


//头插法生成节点
void List::insertList(int data)
{
    Node * cur=new Node;

    //插入数据
    cur->data=data;

    //插入节点
    cur->next =head->next;
    head->next=cur;
}

//调用insertList输入数据，生成链表
void List::input()
{
    cout<<"请输入链表数量长度：";
    cin >>num;
    srand(time(NULL));
    for(int i=0;i<num;i++)
    {
        insertList(rand()%100);
    }
}

//任意位置插入节点
int List::addNode()
{
    int d,idx;

    cout<<"请输入你要插入的节点数据:";
    cin >>d;
    cout<<"请输入你要插入的节点位置: ";
    cin >>idx;

    Node *tp=NULL;
    Node *link=head;

    //寻找插入位置
    if(idx<1||idx>num+1)
        cout<<"操作非法"<<endl;
    else
    {
        for(int i=0;i<idx;i++)
        {
            tp=link;
            link=link->next;
        }

        Node *cur=new Node;
        tp->next=cur;
        cur->data=d;
        cur->next=link;
        travelList();
        return ++num;
    }
}

//遍历链表并将数据存入文件
void List::travelList()
{
    ofstream mycout("D:/text.txt");
    Node *temp = head->next; //防止头指针地址改变
    while(temp != NULL)
    {
        cout<<temp->data<<"  ";
        mycout<<temp->data<<"  ";
        temp=temp->next;
    }
    mycout.close();
    cout<<endl;
}

//删除节点
void List::deleteData(int addNum)
{
    int i,j=0;
    cout<<"请问您要删除第几个数据: ";
    cin >>i;
    Node *tp=NULL;
    Node *link=head;//link为删除节点后面的一个节点，temp为删除节点

    if(addNum<i||i<0)
        cout<<"操作非法！！"<<endl;
    else
    {
        while(link->next)
        {
            tp=link->next; //第一个节点
            j++;
            if(i==j)   //找的删除的节点
            {
                link->next=tp->next;
                delete tp;
                break;
            }
            link=link->next;
        }
        travelList();
    }

}

//清空链表
void List::clearList()
{
    Node *tp = NULL;
    Node *ph=head->next;

    while(head->next)
    {
        tp=ph;
        ph=ph->next;
        delete tp;
        head->next=ph;
    }

    travelList();
    cout<<endl;
}

//询问是否清空
void List::ifClear()
{
    string i;

    if(!head->next)
    {
        cout<<"链表已清空！！！"<<endl;
    }

    else
    {
        cout<<"是否清空链表（yY/nN）：";
        cin>>i;

        if(i=="y" || i=="Y")
        {
            clearList();
            cout<<"链表清空完成！！！"<<endl;
        }
        else
            cout<<"链表未清空！！！"<<endl;
    }
}

int main()
{
    //初始化，生成头节点
    List list;

    //输入链表长度
    list.input();

    //遍历链表，并存入文件
    list.travelList();

    //添加节点并返回总结点数
    int addNum=list.addNode();

    //删除节点
    list.deleteData(addNum);

    //是否清空链表
    list.ifClear();

    //system("pause");
    return 0;

}
