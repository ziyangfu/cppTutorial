/*!
	\brief 组合与委托关系
	\file sample.cpp
*/
#include <iostream>

class Engine {
public:
  Engine() 
  	: val_(100){
  std::cout << "Engine 构造" << std::endl;}
  ~Engine() {
  std::cout << "Engine 析构" << std::endl; }
  void start() {
    std::cout << "Engine 启动." << std::endl;
  }

  void stop() {
    std::cout << "Engine 停止." << std::endl;
  }
  int getVal() const {
	return val_;
  }
  private:
  	int val_;
};

class Seat{
public:
	Seat()
	: num_(5)
	{
	std::cout << "Seat 构造" << std::endl; }
	~Seat() {
	std::cout << "Seat 析构" << std::endl; }
	int getNum() const { return num_;}
private:
	int num_;
};

class Car {
public:
  Car()
  : m_engine(new Engine())
  {
    std::cout << "car 构造" << std::endl;
  }

  ~Car() {
    std::cout << "car 析构" << std::endl;
    delete m_engine;  // 若不删除，Engine对象将还存在
  }

  void start() {
    m_engine->start();
  }

  void stop() {
    m_engine->stop();
  }
  
  Engine* getEngine() const { return m_engine; }

private:
  Seat m_seat;
  Engine* m_engine;
};

int main() {
	// 定义一个空指针，验证委托关系下各对象的生命周期
	Engine* engine = nullptr;
	{
	  Car car;
	  engine = car.getEngine();
	  std::cout << "--------------------------------" << std::endl;
	  car.start(); // 输出: Engine 启动.
	  car.stop();  // 输出: Engine 停止.
	  std::cout << "--------------------------------" << std::endl;
	}  // car已经析构
	std::cout << "--------------------------------" << std::endl;
	// 若delete，则Engine对象清空，值为0，若不delete，值100
	std::cout << engine->getVal() << std::endl;

  return 0;
}
