/*!
	\brief 临时对象的探讨 
*/

#include <iostream>
using namespace std;

class Point {
public:
  Point(int x, int y) : m_x(x), m_y(y) {
    std::cout << "Constructing Point: (" << m_x << ", " << m_y << "); this = " << this << std::endl;
  }
  Point(const Point& p)
  	: m_x(p.m_x),
  	  m_y(p.m_y)
  {
  	cout << "copy construct, Point:(" << m_x << ", " << m_y << "); this = "  << this << endl;
  }
  
  ~Point() {
    std::cout << "Destructing Point: (" << m_x << ", " << m_y << "); this = " << this << std::endl;
  }

  int getX() const { return m_x; }
  int getY() const { return m_y; }

private:
  int m_x;
  int m_y;
};

Point addPoints(const Point& p1, const Point& p2) {
  int sumX = p1.getX() + p2.getX();
  int sumY = p1.getY() + p2.getY();
  return Point(sumX, sumY); // 创建临时对象并返回
}

int main() {
  Point p1(1, 2);
  Point p2(3, 4);
  cout << "----------------------------------------------" << endl;
  Point result = addPoints(p1, p2); // 调用函数返回临时对象
   cout << "----------------------------------------------" << endl;
  std::cout << "Result: (" << result.getX() << ", " << result.getY() << ")" << std::endl;

  return 0;
}
