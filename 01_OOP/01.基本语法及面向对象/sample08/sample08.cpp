/** 函数 */
#include <iostream>
using namespace std;
// 函数默认参数
int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}
//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}


//函数重载需要函数都在同一个作用域下
void func3()
{
	cout << "func 的调用！" << endl;
}
void func3(int a)
{
	cout << "func (int a) 的调用！" << endl;
}
void func3(double a)
{
	cout << "func (double a)的调用！" << endl;
}
void func3(int a ,double b)
{
	cout << "func (int a ,double b) 的调用！" << endl;
}
void func3(double a ,int b)
{
	cout << "func (double a ,int b)的调用！" << endl;
}



int main() {
	cout << "ret = " << func(20, 20) << endl;  // 50
	cout << "ret = " << func(100) << endl;     // 120
    func3();            // func 的调用！
	func3(10);          // func (int a) 的调用！
	func3(3.14);        // func (double a)的调用！
	func3(10,3.14);     // func (int a ,double b) 的调用！
	func3(3.14 , 10);  // func (double a ,int b)的调用！
	return 0;
}