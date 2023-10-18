//
// Created by fzy on 23-10-12.
//

#ifndef CLASSMODELTEST_BASEWITHVRITUAL_HPP
#define CLASSMODELTEST_BASEWITHVRITUAL_HPP

#include <iostream>
/** 带虚函数的简单类对象模型 */
class BaseWithVirtual {
public:
    BaseWithVirtual(){}
    virtual ~BaseWithVirtual(){
        std::cout << "~BaseWithVirtual()" << std::endl;
    }

    void nonstaticFunc1() {
        std::cout << "BaseWithVirtual::nonstaticFunc1" << std::endl;
    }            /**  非静态函数 */
    virtual void virtualFunc1() {
        std::cout << "BaseWithVirtual::virtualFunc1" << std::endl;
    }    /** 虚函数 */
    virtual void virtualFunc2() {
        std::cout << "BaseWithVirtual::virtualFunc2" << std::endl;
    }
    virtual void virtualFunc3() {
        std::cout << "BaseWithVirtual::virtualFunc3" << std::endl;
    }
    virtual void virtualFunc4() {
        std::cout << "BaseWithVirtual::virtualFunc4" << std::endl;
    };
public:
    int _nonstatic_x;
    char _nonstatic_ch;
};

#endif //CLASSMODELTEST_BASEWITHVRITUAL_HPP
