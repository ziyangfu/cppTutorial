#include <iostream>

using namespace std;
class A {
public:
    int var_;
public:
    A(int value =  0 )
        : var_(value)
    {
        cout << "this = " << this;
        cout << "  A(int)构造函数被调用" << endl; }
    A(const A &tmpv) {
        var_ = tmpv.var_;
        cout << "this = " << this;
        cout << "  A拷贝构造函数被调用" << endl; }
    A& operator=(const A &tmpv) {
        var_ = tmpv.var_;
        cout << "this = " << this;
        cout << "  A拷贝赋值运算符被调用" << endl;
        return *this; }
    ~A(){
        cout << "this = " << this;
        cout << "  A析构函数被调用" << endl; }
};
class B{
public:
    A obj_; //类类型对象
public:
    B(int var)
        : obj_(var) {}  // 初始化列表
     //B(int var) {
     //    obj_ = 100;      // 类内赋值
    // }
    int getVar() const { return obj_.var_; }

    //Y(int tmpvalue) :xobj(1000)//这里构造了xobj，此处若没有使用初始化成员列表，耗费了一次构造函数调用的机会
    //B(int tmpvalue)//这里构造了xobj，此处若没有使用初始化成员列表，耗费了一次构造函数调用的机会
    //Y(int var) {
     //   xobj.m_i = 1000;
   // }
    // 编译器角度(没用初始化列表)
    //X xobj;
    //xobj.X::X();
    // 编译器角度(用了初始化列表)
    //X xobj;
    //xobj.X::X(1000);

        //xobj = 1000;//若不使用初始化列表。这里构造一个临时对象，把临时对象内容给了xobj，之后释放xobj
        //编译器视角
        //x tmpobj;//                          （1）生成临时对象
        //tmpobj.X::X(1000);//                 （2）临时对象调用构造函数
        //xobj.X::operator=(tmpobj);//         （3）调用拷贝赋值运算符
        //tmpobj.X::~X();      //              （4）调用析构函数

};


int main() {
    B b(100);
    cout << "mi = " << b.getVar() << endl;
    return 0;
}