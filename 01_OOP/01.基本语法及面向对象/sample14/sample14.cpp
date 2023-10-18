/*!
	\brief 深拷贝与浅拷贝 
	\file sample14.cpp
*/
#include <iostream>
#include <cstring>


class Person {
public:
  Person(const char* name, int age) {
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    m_age = age;
  }

  // 深拷贝构造函数
  Person(const Person& other) {
    std::cout << "调用拷贝构造" << std::endl;
    m_name = new char[strlen(other.m_name) + 1];
    strcpy(m_name, other.m_name);
    m_age = other.m_age;
  }

  // 深拷贝赋值运算符重载
  Person& operator=(const Person& other) {
  std::cout << "调用赋值构造" << std::endl;
    if (this != &other) {
      delete[] m_name;
      m_name = new char[strlen(other.m_name) + 1];
      strcpy(m_name, other.m_name);
      m_age = other.m_age;
    }
    return *this;
  }

  ~Person() {
    delete[] m_name;
  }

  void printInfo() {
    std::cout << "Name: " << m_name << ", Age: " << m_age << std::endl;
    printf("m_name指针是： %p\n", m_name);
  }

private:
  char* m_name;
  int m_age;
};

class Person2 {
public:
  Person2(const char* name, int age) {
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    m_age = age;
  }
 // 使用默认拷贝构造与赋值构造，默认是浅拷贝
  ~Person2() {
    delete[] m_name;
  }

  void printInfo() {
    std::cout << "Name: " << m_name << ", Age: " << m_age << std::endl;
    printf("m_name指针是： %p\n", m_name);
  }
private:
	char* m_name;
	int m_age;
};

int main() {
  Person p1("Alice", 25);
  Person p2 = p1; // 深拷贝，p2和p1共享m_name指针

  p1.printInfo(); // 输出: Name: Alice, Age: 25 m_name指针是： 0x55d75e3bceb0
  p2.printInfo(); // 输出: Name: Alice, Age: 25 m_name指针是： 0x55d75e3bd2e0


  p2 = Person("Bob", 30); // 深拷贝，p2拥有自己的m_name指针

  p1.printInfo(); // 输出: Name: Alice, Age: 25 m_name指针是： 0x55d75e3bceb0
  p2.printInfo(); // 输出: Name: Bob, Age: 30   m_name指针是： 0x55d75e3bd2e0
  std::cout << "----------------------------------------" << std::endl;
  
  Person2 p3("Jerry", 5);
  Person2 p4 = p3; // 浅拷贝，p3和p4共享m_name指针
  p3.printInfo(); // 输出: Name: Jerry, Age: 5  m_name指针是： 0x55d75e3bd300
  p4.printInfo(); // 输出: Name: Jerry, Age: 5  m_name指针是： 0x55d75e3bd300
  std::cout << "----------------------------------------" << std::endl;
  return 0;
  // 析构时，报错，因为p3与p4指向同一块内存，重复释放
  // free(): double free detected in tcache 2
  // Aborted (core dumped)
}
