#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

//��
class List
{
public:
    //��������ʼ��������ͷ�ڵ�
    List()
    {
        head = new Node;
        head->next=NULL;
    }

    //��Ա����
    void createList();
    void insertList(int data);
    void travelList();
    void input();
    int  addNode();
    void deleteData(int addNum);
    void ifClear();
    void clearList();
private:
    //���ݳ�Ա
    struct Node
    {
        int data; //������
        struct Node * next; //ָ����

    } * head;//ͷָ��

    int num;//����Ԫ�ظ���
};


//ͷ�巨���ɽڵ�
void List::insertList(int data)
{
    Node * cur=new Node;

    //��������
    cur->data=data;

    //����ڵ�
    cur->next =head->next;
    head->next=cur;
}

//����insertList�������ݣ���������
void List::input()
{
    cout<<"�����������������ȣ�";
    cin >>num;
    srand(time(NULL));
    for(int i=0;i<num;i++)
    {
        insertList(rand()%100);
    }
}

//����λ�ò���ڵ�
int List::addNode()
{
    int d,idx;

    cout<<"��������Ҫ����Ľڵ�����:";
    cin >>d;
    cout<<"��������Ҫ����Ľڵ�λ��: ";
    cin >>idx;

    Node *tp=NULL;
    Node *link=head;

    //Ѱ�Ҳ���λ��
    if(idx<1||idx>num+1)
        cout<<"�����Ƿ�"<<endl;
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

//�������������ݴ����ļ�
void List::travelList()
{
    ofstream mycout("D:/text.txt");
    Node *temp = head->next; //��ֹͷָ���ַ�ı�
    while(temp != NULL)
    {
        cout<<temp->data<<"  ";
        mycout<<temp->data<<"  ";
        temp=temp->next;
    }
    mycout.close();
    cout<<endl;
}

//ɾ���ڵ�
void List::deleteData(int addNum)
{
    int i,j=0;
    cout<<"������Ҫɾ���ڼ�������: ";
    cin >>i;
    Node *tp=NULL;
    Node *link=head;//linkΪɾ���ڵ�����һ���ڵ㣬tempΪɾ���ڵ�

    if(addNum<i||i<0)
        cout<<"�����Ƿ�����"<<endl;
    else
    {
        while(link->next)
        {
            tp=link->next; //��һ���ڵ�
            j++;
            if(i==j)   //�ҵ�ɾ���Ľڵ�
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

//�������
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

//ѯ���Ƿ����
void List::ifClear()
{
    string i;

    if(!head->next)
    {
        cout<<"��������գ�����"<<endl;
    }

    else
    {
        cout<<"�Ƿ��������yY/nN����";
        cin>>i;

        if(i=="y" || i=="Y")
        {
            clearList();
            cout<<"���������ɣ�����"<<endl;
        }
        else
            cout<<"����δ��գ�����"<<endl;
    }
}

int main()
{
    //��ʼ��������ͷ�ڵ�
    List list;

    //����������
    list.input();

    //���������������ļ�
    list.travelList();

    //��ӽڵ㲢�����ܽ����
    int addNum=list.addNode();

    //ɾ���ڵ�
    list.deleteData(addNum);

    //�Ƿ��������
    list.ifClear();

    //system("pause");
    return 0;

}
