
#include <iostream>
using namespace   std;
class B;
class A
{
	int a;
public:
	A(int x=0) { a=x; }
	friend void fun(B&); //��ע�͵��˾����޷�ͨ������
	virtual ~A(){} //���������������һ��������������һ����ϰ�ߣ��������������Ƿ������Ҫ
};

class B: public A
{
public:
	B(int x): A(x) {}
};

void fun(B& o)
{
	cout << o.a << endl;
}

int main()
{
	//A a(55);
	B b(66);
	//fun(a);
	fun(b);
}
