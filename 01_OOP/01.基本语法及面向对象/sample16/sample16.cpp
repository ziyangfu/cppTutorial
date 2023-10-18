/*!
	\brief pimpl编程技法
	\file sample16.cpp  
*/

class AImpl;  

class A {  
public:  
    A() 
    : impl_(new AImpl)  
    {
    }
    ~A() {
    	delete impl_; 
    }
    void func() {   // 对外调用接口
    	impl_->func();
    } 

private:  
    A(const A&);  
    void operator=(const A&);  
    AImpl* impl_;  
}；  

class AImpl {  
public:  
    void func();  
private:  
    int  myFunc(int myParam);  // 具体功能实现
private:  
    int  _myVariable;  
};  

