/** sample01.cpp */
#include <iostream> // 标准输入输出函数库
#include <vector>   // C++ STL容器
#include "root.h"   // 用户头文件
using namespace std; //使用标准命名空间

int main() //主函数
{
      double a, b; // 定义两个浮点型变量
      cin >> a >> b ;// 输入两个数
      vector<double> data;  // 定义一个vector数组
      data.push_back(a);
      data.push_back(b);
      cout << "a = " << data[0] << " b = " << data[1] << endl;
      cout << root(a,b) << endl; // 输出a-b的平方根
      return 0; // 主函数正常结束返回0
}
