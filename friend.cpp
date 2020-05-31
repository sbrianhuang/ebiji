
#include <iostream>
using namespace   std;
class B;
class A
{
	int a;
public:
	A(int x=0) { a=x; }
	friend void fun(B&); //若注释掉此句则无法通过编译
	virtual ~A(){} //用作基类的类皆添加一个虚析构函数是一个好习惯，无论析构函数是否真的需要
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
