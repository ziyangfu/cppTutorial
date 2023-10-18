//
// Created by fzy on 23-10-12.
//

#ifndef CLASSMODELTEST_INHERIT_HPP
#define CLASSMODELTEST_INHERIT_HPP

#include "Base.hpp"

/** 单继承类对象模型 */
class Inherit01 : public Base {
public:
    int _inherit01_int;
    char _inherit01_char;
};

class Inherit02 : public Inherit01 {
public:
    int _inherit02_char;
};


#endif //CLASSMODELTEST_INHERIT_HPP
