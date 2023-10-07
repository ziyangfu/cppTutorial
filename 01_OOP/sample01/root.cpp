/** sample01， root.cpp */
#include "root.h"
#include <cmath> //数学函数库 
// #include <math.h>  // C风格
using namespace std;
double root(double x, double y)
{
      if(x >= y) 
            return sqrt(x-y);
      else 
            return 0; 
}
