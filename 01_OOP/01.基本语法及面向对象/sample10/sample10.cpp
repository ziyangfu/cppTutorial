/*!
	\brief 枚举与枚举类 
*/
#include <iostream>

using namespace std;

enum Sex2 { Girl,  Boy };
// 错误，编译器提示 Girl，Boy重定义
//enum Student { Girl,  Boy };
// enum class能够有效对枚举作用域进行限定，避免了枚举成员的重定义
enum class Sex { Girl,  Boy };
enum class Student{ Girl,  Boy };
int main()
{
 Sex2 a1 = Girl;
 printf("%d\n", a1);  // 0
 Sex a = Sex::Girl;
 printf("%d\n", a);   // 0
 Student b = Student::Boy;
 printf("%d\n", b);   // 1
 //两者处于不同作用域下，不会重定义
}
