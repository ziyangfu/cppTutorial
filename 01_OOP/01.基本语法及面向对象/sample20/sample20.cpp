/** 
  \brief 多重继承的二义性问题 */

#include <iostream>
using namespace std;
// sample20.cpp
class A {
public:
    void fun() { cout<<"a.fun"<<endl; }
};
class B {
public:
    void fun() { cout<<"b.fun"<<endl; }
    void gun() { cout<<"b.gun"<<endl; }
};
class C:public A,public B {
public:
    void gun() { cout<<"c.gun"<<endl; } //重写gun()
    // error: reference to ‘fun’ is ambiguous
    // void hun() { fun(); } //类内出现二义性问题
    void hun() { A::fun(); } // 明确调用对象，消除二义性
};
int main()
{
    C c;
    C* p = &c;
    c.hun(); // a.fun
    c.A::fun(); //成员名限定消除二义性 a.fun
    c.B::fun(); //成员名限定消除二义性 b.fun
    p->A::fun(); //成员名限定消除二义性 a.fun
    p->B::fun(); //成员名限定消除二义性 b.fun
    return 0;
}