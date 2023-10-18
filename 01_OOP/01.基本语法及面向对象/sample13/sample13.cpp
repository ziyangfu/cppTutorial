/*!
	\brief this指针 */

#include <iostream>
class MyClass {
public:
  MyClass(int value) : m_value(value) {
    std::cout << "this = " << this << std::endl;
  }
  void printValue() const {
    std::cout << "Value: " << this->m_value << std::endl;
  }
  void setValue(int value) {
    this->m_value = value;
  }
private:
  int m_value;
};
int main() {
  MyClass obj1(10);
  MyClass obj2(20);
  obj1.printValue();  // 输出: Value: 10
  obj2.printValue();  // 输出: Value: 20
  
  obj1.setValue(30);
  obj2.setValue(40);

  obj1.printValue();  // 输出: Value: 30
  obj2.printValue();  // 输出: Value: 40
  return 0;
}
