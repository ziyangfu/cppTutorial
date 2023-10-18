/*!
	\brief 继承关系
	\file sample17.cpp  
*/

#include <iostream>
#include <string>

class Animal {
public:
  Animal(const std::string& name) : m_name(name) {}

  void eat() {
    std::cout << m_name << " is eating." << std::endl;
  }

  void sleep() {
    std::cout << m_name << " is sleeping." << std::endl;
  }
protected:
  std::string m_name;
};

class Cat : public Animal {
public:
  Cat(const std::string& name) : Animal(name) {}
  // 喵喵喵~~
  void meow() {  
    std::cout << m_name << " says meow." << std::endl;
  }
};

class Dog : public Animal {
public:
  Dog(const std::string& name) : Animal(name) {}
  // 汪汪汪~~
  void bark() {
    std::cout << m_name << " says bark." << std::endl;
  }
};

int main() {
  Cat cat("Tom");
  cat.eat();  // 输出: Tom is eating.
  cat.sleep();  // 输出: Tom is sleeping.
  cat.meow();  // 输出: Tom says meow.

  Dog dog("Max");
  dog.eat();  // 输出: Max is eating.
  dog.sleep();  // 输出: Max is sleeping.
  dog.bark();  // 输出: Max says bark.

  return 0;
}

