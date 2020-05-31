#include <iostream>
#include <string>
#include <list>
using namespace std;

class Subject;
//����۲���
class Observer
{
protected:
    string name;
    Subject *sub;
public:
    Observer(string name, Subject *sub)
    {
        this->name = name;
        this->sub = sub;
    }
    const char* getname();
    virtual void update() = 0;
};
const char* Observer::getname()
{
    return name.c_str();
}
//����Ĺ۲��ߣ�����Ʊ��
class StockObserver :public Observer
{
public:
    StockObserver(string name, Subject *sub) :Observer(name, sub)
    {
    }
    void update();
};
//����Ĺ۲��ߣ���NBA��
class NBAObserver :public Observer
{
public:
    NBAObserver(string name, Subject *sub) :Observer(name, sub)
    {
    }
    void update();
};
//����֪ͨ��
class Subject
{
protected:
    list<Observer*> observers;
public:
    string action;
    virtual void attach(Observer*) = 0;
    virtual void detach(Observer*) = 0;
    virtual void notify() = 0;
};
//����֪ͨ�ߣ�����
class Secretary :public Subject
{
    void attach(Observer *observer)
    {
        observers.push_back(observer);
    }
    void detach(Observer *observer)
    {
        list<Observer *>::iterator iter = observers.begin();
        while (iter != observers.end())
        {
            if ((*iter) == observer)
            {
                cout<<"erase"<<observer->getname()<< (*iter)<<endl;
                observers.erase(iter++);
                //++iter;
            }
            else
            {
                ++iter;
            }
        }
    }
    void notify()
    {
        list<Observer *>::iterator iter = observers.begin();
        while (iter != observers.end())
        {
            (*iter)->update();
            ++iter;
        }
    }
};

void StockObserver::update()
{
    cout << name << " �յ���Ϣ��" << sub->action << endl;
    if (sub->action == "����������!")
    {
        cout << "�����Ϲرչ�Ʊ��װ�������湤�������ӣ�" << endl;
    }
    else
    {
        cout <<"���ҵ��£���ƱҪ����"<<endl;
    }
}

void NBAObserver::update()
{
    cout << name << " �յ���Ϣ��" << sub->action << endl;
    if (sub->action == "����������!")
    {
        cout << "�����Ϲر�NBA��װ�������湤�������ӣ�" << endl;
    }
    else
    {
        cout <<"�����������ɱ�ˣ�"<<endl;
    }
}

int main()
{
    Subject *dwq = new Secretary(); //�����۲���//���۲�Ķ���
    Observer *xs = new NBAObserver("xiaoshuai", dwq);
    Observer *zy = new NBAObserver("zouyue", dwq);
    Observer *lm = new StockObserver("limin", dwq);
    Observer *hb = new StockObserver("huangshengbin", dwq);
//����۲����
    dwq->attach(xs);
    dwq->attach(zy);
    dwq->attach(lm);
    dwq->attach(hb);
//�¼�
    dwq->action = "ȥ�Է��ˣ�";//֪ͨ
    dwq->notify();
    cout << endl;
    dwq->action = "����������!";
    dwq->notify();

    dwq->detach(xs);
    dwq->detach(zy);
    dwq->detach(lm);
    dwq->detach(hb);

    delete dwq;
    delete xs;
    delete zy;
    delete lm;
    delete hb;
    return 0;
}
