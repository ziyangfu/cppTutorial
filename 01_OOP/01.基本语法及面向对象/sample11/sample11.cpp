/**
\brief constexpr常量表达式 */

#include <iostream>
#include <string>

using namespace std;

constexpr int get_sz() {
    return 5;
}

int main()
{
const char* str1 = "Hello World";
const std::string str2 = "Hello World";

constexpr int mf = 20;		// mf是常量表达式
constexpr int limit = mf + 1;	// limit 是常量表达式
constexpr int sz = get_sz();	// 只有当 get_sz() 是一个 constexpr 函数时才是一条正确的声明语句

cout << mf << endl;
cout << limit << endl;
cout << sz << endl;
}
