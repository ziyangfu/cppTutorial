/** sample03, sample03.cpp */
#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(const string name, int age){
        name_ = name;
        age_ = age;
        cout << "调用有参构造" << endl;
    }
    Person(){
        cout << "调用默认构造函数 " << endl;
    }

    Person(const Person& p) {
        name_ = p.getName();
        age_ = p.getAge();
        cout << "调用拷贝构造函数 " << endl;
    }

    Person& operator=(const Person& p) {
        //name_ = p.getName();
        //age_ = p.getAge();
        cout << "调用赋值构造函数 " << endl;
        return *this;
    }
    ~Person() {
       cout << "调用析构函数 " << endl; 
    }

    const string& getName() const {
        return name_;
    }
    const int getAge() const {
        return age_;
    }
    int getSize() {
        return name_.size();
    }
private:
    string name_;
    int age_;
};

#if 0
class Person2 {
public:
    Person2(const string name, int age)
        :name_(name),
         age_(age)
    {
        cout << "调用有参构造" << endl;
    }
    Person2(){
        cout << "调用默认构造函数 " << endl;
    }

    Person2(const Person2& p) {
        name_ = p.getName();
        age_ = p.getAge();
        cout << "调用拷贝构造函数 " << endl;
    }

    Person2& operator=(const Person2& p) {
        //name_ = p.getName();
        //age_ = p.getAge();
        cout << "调用赋值构造函数 " << endl;
        return *this;
    }
    ~Person2() {
       cout << "调用析构函数 " << endl; 
    }

    const string& getName() const {
        return name_;
    }
    const int getAge() const {
        return age_;
    }
private:
    string name_;
    int age_;
};
#endif

int main() {
    {
        cout << "现在是非初始化列表" << endl;
        Person p("Tom", 18);
        cout << p.getName() << "  " << p.getSize() << "  " << p.getAge() << endl;
    }
    cout << "--------------------------------------------" << endl;
    {
        //cout << "现在是初始化列表" << endl;
       // Person2 p("jerry", 15);
       // cout << p.getName() << "  " << p.getAge() << endl;
    }

    
    return 0;
}
