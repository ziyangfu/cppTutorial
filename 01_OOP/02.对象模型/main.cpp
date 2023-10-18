#include <iostream>
#include "Base.hpp"
#include "BaseWithVritual.hpp"
#include "Inherit.hpp"
#include "InheritWithVirtual.hpp"
#include "Composition.hpp"
#include "Agreegation.hpp"

using namespace std;
void simpleClassTest() {
    cout << "简单类对象模型测试：" << endl;
    cout << "空类的大小：" << sizeof(EmptyClass) << endl;
    Base b;
    cout << "Base对象的大小：" << sizeof(b) << endl;
    cout << "Base对象的地址：" << &b << endl;
    cout << "非静态变量地址：_nonstatic_x = " << &b._nonstatic_x << endl;
    cout << "非静态变量地址：_nonstatic_ch = " << static_cast<void*>(&b._nonstatic_ch) << endl;
    cout << "静态变量地址：_static_x = " << &b._static_x << endl;
}

void virtualSimpleClassTest() {
    cout << "带虚函数的简单类对象模型测试：" << endl;
    BaseWithVirtual b;
    cout << "BaseWithVirtual对象的大小：" << sizeof(b) << endl;
    cout << "BaseWithVirtual对象的地址：" << &b << endl;
    cout << "非静态变量地址：_nonstatic_x = " << &b._nonstatic_x << endl;
    cout << "非静态变量地址：_nonstatic_ch = " << static_cast<void*>(&b._nonstatic_ch) << endl;
    cout << "虚函数指针地址： vptr = " << &b << endl;

    cout << "使用虚函数指针与虚函数表调用虚函数：" << endl;
    void** vptr = (void**)(int*)( *(int**)(&b) );  /** 获得虚函数指针指向的虚函数表地址 */
    typedef void(*funcPtr)();  /** 一个函数指针 */
    /** 0与1是虚析构函数，从2开始是虚函数func1~4 */
    for (int i = 2; i < 6; i++) {
        cout << "第 " << i + 1 << " 个虚函数手动调用： ";
        funcPtr p = (funcPtr)vptr[i];  /** 获得函数地址 */
        p();  /** 手动调用虚函数 */
    }
}

void inheritTest() {
    cout << "单继承类对象模型测试：" << endl;
    Inherit01 h1;
    cout << "Inherit01对象的大小：" << sizeof(h1) << endl;
    cout << "Inherit01对象的地址：" << &h1 << endl;
    cout << "Inherit01：_nonstatic_x = " << &h1._nonstatic_x << endl;
    cout << "Inherit01：_nonstatic_ch = " << static_cast<void*>(&h1._nonstatic_ch) << endl;
    cout << "inherit01: _inherit01_int = " << &h1._inherit01_int << endl;
    cout << "inherit01: _inherit02_int =" << static_cast<void*>(&h1._inherit01_char) << endl;
    Inherit02 h2;
    cout << "Inherit02对象的大小：" << sizeof(h2) << endl;
    cout << "Inherit02对象的地址：" << &h2 << endl;
    cout << "Inherit02：_nonstatic_x = " << &h2._nonstatic_x << endl;
    cout << "Inherit02：_nonstatic_ch = " << static_cast<void*>(&h2._nonstatic_ch) << endl;
    cout << "inherit02: _inherit01_int = " << &h2._inherit01_int << endl;
    cout << "inherit02: _inherit02_int =" << static_cast<void*>(&h2._inherit01_char) << endl;
    cout << "inherit02: _inherit02_char = " << static_cast<void*>(&h2._inherit02_char) << endl;
}

void virtualInheritTest() {
    cout << "带虚函数的单继承类对象模型测试：" << endl;
    InheritWithVirtual01 v1;
    InheritWithVirtual02 v2;
    cout << "------------------------------------------------" << endl;
    cout << "常规用法：" << endl;
    cout << "调用v1.virtualFunc1()时， "; v1.virtualFunc1();
    cout << "调用v1.virtualFunc2()时， "; v1.virtualFunc2();
    cout << "调用v1.virtualFunc3()时， "; v1.virtualFunc3();
    cout << "调用v2.virtualFunc1()时， "; v2.virtualFunc1();
    cout << "调用v2.virtualFunc2()时， "; v2.virtualFunc2();
    cout << "调用v2.virtualFunc3()时， "; v2.virtualFunc3();
    cout << "调用v2.virtualFunc4()时， "; v2.virtualFunc4();
    cout << "------------------------------------------------" << endl;
    cout << "内部实现机制探讨：" << endl;
    cout << "InheritWithVirtual01对象的大小：" << sizeof(v1) << endl;
    cout << "InheritWithVirtual01对象的地址：" << &v1 << endl;
    cout << "InheritWithVirtual01：_nonstatic_x = " << &v1._nonstatic_x << endl;
    cout << "InheritWithVirtual01：_nonstatic_ch" << static_cast<void*>(&v1._nonstatic_ch) << endl;

    cout << "InheritWithVirtual01的虚函数指针地址： vptr = " << &v1 << endl;
    cout << "InheritWithVirtual02的虚函数指针地址： vptr2 = " << &v2 << endl;
    cout << "使用虚函数指针与虚函数表调用虚函数：" << endl;
    cout << "InheritWithVirtual01: " << endl;
    void** vptr = (void**)(int*)( *(int**)(&v1) );  /** 获得虚函数指针指向的虚函数表地址 */
    typedef void(*funcPtr)();  /** 一个函数指针 */
    /** 0与1是虚析构函数，从2开始是虚函数func1~4 */
    for (int i = 2; i < 6; i++) {
        cout << "第 " << i + 1 << " 个虚函数手动调用： ";
        funcPtr p = (funcPtr)vptr[i];  /** 获得函数地址 */
        p();  /** 手动调用虚函数 */
    }
    cout << "InheritWithVirtual02: " << endl;
    void** vptr2 = (void**)(int*)( *(int**)(&v2) );  /** 获得虚函数指针指向的虚函数表地址 */
    /** 0与1是虚析构函数，从2开始是虚函数func1~4 */
    for (int i = 2; i < 6; i++) {
        cout << "第 " << i + 1 << " 个虚函数手动调用： ";
        funcPtr p2 = (funcPtr)vptr2[i];  /** 获得函数地址 */
        p2();  /** 手动调用虚函数 */
    }
}

void compositionTest(){
    Car car("MG", "MG7");
    //car.start();
    //car.stop();
    cout << " 组合关系对象模型测试：" << endl;
    cout << "Car对象的大小：" << sizeof(car) << endl;
    cout << "Engine对象的大小： " << sizeof(car.m_engine) << endl;
    cout << "Car对象的地址：" << &car << endl;
    cout << "    变量地址：m_brand = " << &car.m_brand << endl;
    cout << "    变量地址：m_model = " << &car.m_model << endl;
    cout << "    变量地址：m_engine = " << &car.m_engine << endl;
    cout << "Engine对象的地址：" << &car.m_engine << endl;
    cout << "    变量地址：m_torque = " << &car.m_engine.m_torque << endl;
    cout << "    变量地址：m_brand = " <<  &car.m_engine.m_brand << endl;
}

void agreegationTest(){
    Car02 car("MG", "MG7");
    //car.start();
    //car.stop();
    cout << "委托关系对象模型测试：" << endl;
    cout << "Car对象的大小：" << sizeof(car) << endl;
    cout << "Engine对象的大小： " << sizeof(*car.m_engine) << endl;
    cout << "Car对象的地址：" << &car << endl;
    cout << "    变量地址：m_brand = " << &car.m_brand << endl;
    cout << "    变量地址：m_model = " << &car.m_model << endl;
    cout << "    变量地址：m_engine = " << &car.m_engine << endl;
    cout << "Engine对象的地址：" << car.m_engine << endl;
    cout << "    变量地址：m_torque = " << &car.m_engine->m_torque << endl;
    cout << "    变量地址：m_brand = " <<  &car.m_engine->m_brand << endl;
}

void mInheritTest(){
    cout << "多继承类对象模型测试：" << endl;
}

void diamondInheritTest() {
    cout << "菱形继承类对象模型测试：" << endl;
}

int main() {
    // simpleClassTest();
    // virtualSimpleClassTest();
    // inheritTest();
    // virtualInheritTest();
    // compositionTest();
    agreegationTest();
    return 0;
}
