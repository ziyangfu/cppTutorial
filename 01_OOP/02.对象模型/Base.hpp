//
// Created by fzy on 23-10-12.
//

#ifndef CLASSMODELTEST_BASE_HPP
#define CLASSMODELTEST_BASE_HPP

/** 空类大小 */
class EmptyClass {};

/** 简单类对象模型测试 */
class Base {
public:
    Base()
            : _nonstatic_x(90),
              _nonstatic_ch('a')
    {}
    ~Base() {};
    static void staticFunc(){} /** 静态函数 */
    void nonstaticFunc(){}     /** 普通函数 */

public:
    int _nonstatic_x;        /** 非静态变量 */
    static int _static_x;    /** 静态变量 */
    char _nonstatic_ch;
};
int Base::_static_x = 100;

#endif //CLASSMODELTEST_BASE_HPP
