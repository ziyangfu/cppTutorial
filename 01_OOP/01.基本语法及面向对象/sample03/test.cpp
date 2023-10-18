#include <iostream>

class Base {
public:
    Base(double var)
        : var_(var) 
    {}

    virtual ~Base() {}

virtual void getAAA() = 0; 
private:
    double var_;
};
class Base2 {};

class FZY : public Base {
public:
    FZY(int age, double var)
        : myTestAge_(age),
          Base(var)
    {}
    ~FZY() {}   

    void getAAA() override {}
private:
    int myTestAge_;
};

int main() {
    FZY f(18, 3.14);
    
    std::cout << sizeof(f) << std::endl;

    Base2 b;

    std::cout << sizeof(b) << std::endl;
    //std::cout << &f << std::endl;
    return 0;
}