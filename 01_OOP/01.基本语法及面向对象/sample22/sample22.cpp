/** 
  \brief 虚函数的使用 */

#include <iostream>
#include <string>
using namespace std;
// sample22.cpp

// 基类
class Animal {
public:
    Animal(const std::string& name) : name(name) {}
	virtual ~Animal(){};   // 虚虚构函数
    // 非虚函数
    void MakeSound() {
        std::cout << name << " makes a generic animal sound." << std::endl;
    }
    // 虚函数
    virtual void Eat() {
        std::cout << name << " eats something." << std::endl;
    }
    // 纯虚函数（抽象函数）
    virtual void Sleep() = 0;
private:
    std::string name;
};

// 派生类
class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {}
	virtual ~Dog() {}

    // 重写虚函数
    void Eat() override {
        std::cout << "Dog " << " eats dog food." << std::endl;
    }

    // 实现纯虚函数
    void Sleep() override {
        std::cout << "Dog " << " sleeps in a dog bed." << std::endl;
    }

    // 新的函数
    void Bark() {
        std::cout << "Dog " << " barks loudly." << std::endl;
    }
};

int main() {
    Animal* animal = new Dog("Buddy");

    // 非虚函数调用基类版本
    animal->MakeSound(); //  Buddy makes a generic animal sound.


    // 虚函数调用派生类版本
    animal->Eat(); // Dog  eats dog food
  
    // 纯虚函数通过派生类实现
    animal->Sleep();  // Dog  sleeps in a dog bed.

    // 非虚函数不能动态绑定，因此调用基类版本
    Dog* dog = dynamic_cast<Dog*>(animal);
    if (dog) {
        dog->Bark();  // Dog  barks loudly.
    }

    delete animal;
    return 0;
}
