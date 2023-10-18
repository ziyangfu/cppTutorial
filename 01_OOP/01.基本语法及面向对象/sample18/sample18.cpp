/*!
	\brief 私有继承与保护继承
	\file sample18.cpp  
*/

#include <iostream>
#include <string>

class Base {
public:
  void publicFunction() {
    std::cout << "Base public function" << std::endl;
  }

protected:
  void protectedFunction() {
    std::cout << "Base protected function" << std::endl;
  }

private:
  void privateFunction() {
    std::cout << "Base private function" << std::endl;
  }
};

class Derived : private Base {  // 私有继承
public:
  void derivedFunction() {
    publicFunction();  // 可以访问基类的公有函数
    protectedFunction();  // 可以访问基类的保护函数
    // privateFunction();  // 无法直接访问基类的私有函数

    std::cout << "Derived function" << std::endl;
  }
};

class Derived2 : protected Base {   // 保护继承
public:
  void derivedFunction() {
    publicFunction();  // 可以访问基类的公有函数
    protectedFunction();  // 可以访问基类的保护函数
    // privateFunction();  // 无法直接访问基类的私有函数

    std::cout << "Derived function" << std::endl;
  }
};

int main() {
  Derived derived;
  derived.derivedFunction();
  // derived.publicFunction();  // 错误，无法直接访问基类的公有函数
  // derived.protectedFunction();  // 错误，无法直接访问基类的保护函数
  std::cout << "--------------------------------------------------" << std::endl;
  Derived2 derived2;
  derived2.derivedFunction();
  // derived2.publicFunction();  // 错误，无法直接访问基类的公有函数
  // derived2.protectedFunction();  // 错误，无法直接访问基类的保护函数

  return 0;
}