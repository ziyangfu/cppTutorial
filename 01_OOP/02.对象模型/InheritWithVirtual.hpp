//
// Created by fzy on 23-10-12.
//

#ifndef CLASSMODELTEST_INHERITWITHVIRTUAL_HPP
#define CLASSMODELTEST_INHERITWITHVIRTUAL_HPP

#include "BaseWithVritual.hpp"
#include <iostream>

/** 带虚函数的单继承对象模型 */
class InheritWithVirtual01 : public BaseWithVirtual {
public:
    InheritWithVirtual01() = default;
    virtual ~InheritWithVirtual01() {}
    void v1Func01() {}
    /** 重写虚函数 */
    void virtualFunc1() override {
        std::cout << "InheritWithVirtual01::virtualFunc1()" << std::endl;
    }
public:
    int inherit01_int;
};

class InheritWithVirtual02 : public InheritWithVirtual01{
public:
    InheritWithVirtual02() = default;
    virtual ~InheritWithVirtual02(){};
    void v2Func02() {}
    /** 重写虚函数 */
    void virtualFunc3() override {
        std::cout << "InheritWithVirtual02::virtualFunc3()" << std::endl;
    }
    void virtualFunc4() override {
        std::cout << "InheritWithVirtual02::virtualFunc4()" << std::endl;
    }
public:
    int inherit02_int;
};

#endif //CLASSMODELTEST_INHERITWITHVIRTUAL_HPP
