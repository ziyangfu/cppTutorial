/** sample02 sample02.cpp */
#include <iostream>
using namespace std;
int main() {
	#ifdef __x86_64__
         cout << "当前运行在64位机器上" << endl;  // 64位下
   	#elif __i386__
         cout << "当前运行在32位机器上" << endl;
   	#endif	
	cout << "short 类型所占内存空间为： " << sizeof(short) << endl;  	// 2
	cout << "int 类型所占内存空间为： " << sizeof(int) << endl;		// 4
	cout << "long 类型所占内存空间为： " << sizeof(long) << endl;		// 8
	cout << "long long 类型所占内存空间为： " << sizeof(long long) << endl;// 8
	cout << "float 类型所占内存空间为： " << sizeof(float) << endl;	// 4
	cout << "double 类型所占内存空间为： " << sizeof(double) << endl;	// 8

	return 0;
}
