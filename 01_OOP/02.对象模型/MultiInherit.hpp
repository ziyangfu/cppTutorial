//
// Created by fzy on 23-10-12.
//

#ifndef CLASSMODELTEST_MULTIINHERIT_HPP
#define CLASSMODELTEST_MULTIINHERIT_HPP
/** 多继承对象模型测试 */
class Base01
{
public:
    int base01_int;
    char base01_char;
};

class Base02
{
public:
    int base02_int;
    char base02_char;
};

class MultiInherit: public Base01,
                    public Base02
{
public:
    char multiInherit_char;
};

#endif //CLASSMODELTEST_MULTIINHERIT_HPP
