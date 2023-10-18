/** 
  \brief 多重继承的二义性问题，虚继承 */

#include <iostream>
using namespace std;
// sample21.cpp
class Base {
public:
	Base(){}
	~Base(){}
	void Display() {
		std::cout << "Base::Hello" << std::endl;
	}
protected:
	uint32_t data_ = 11;
};

class A: virtual public Base {  // 虚继承
public:
	A(){}
	~A(){}

protected:
	uint32_t data_a_ = 10;
};

class B : virtual public Base { // 虚继承
public:
	B() {}
	~B() {}

protected:
	uint32_t data_b_ = 11;
};

class C :public A, public B {
public:
	C(){}
	~C(){}

	void Show() {
        // 若无虚继承，将编译错误，二义性问题
		std::cout << data_ << std::endl;   // 11
		std::cout << A::data_ << std::endl; // 11
		Display();  //若无虚继承, 将编译错误，二义性问题   // Base::Hello
		A::Display();  // Base::Hello
	}
};

int main() {
    C c;
    c.Show();
    return 0;
}