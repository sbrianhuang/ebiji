#include <iostream>
#include <stdio.h>
class A
{
public:
    virtual void fun();
};
void A::fun()
{
    printf("hello world a\n");
}
class B: public A
{
public:
    ////void fun() override;
};

//void B::fun()
//{
//    printf("hello world b\n");
//}

int main()
{
    A a;
    B b;
    a.fun();
    b.fun();
    return 0;
}
