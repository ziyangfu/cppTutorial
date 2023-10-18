/*!
	\brief 引用的使用 
*/
#include <iostream>

using namespace std;

//1. 值传递
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
//2. 地址传递
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//3. 引用传递
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	int a = 10;
	int b = 20;

	mySwap01(a, b);
	cout << "a:" << a << " b:" << b << endl;  // 主函数未交换，10, 20

	mySwap02(&a, &b);
	cout << "a:" << a << " b:" << b << endl;  //已交换 20, 10

	mySwap03(a, b);
	cout << "a:" << a << " b:" << b << endl;  //已交换 10, 20

	return 0;
}
