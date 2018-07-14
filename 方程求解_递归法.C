#include <stdio.h>
#include <math.h>
/*
与张文龙讨论递归与迭代的不同。
这种方法是求解方程（函数零点）的方法
与常用的切线法不同。
之所以数值计算上不推荐这种方法，是因为如果斜率太大或太小时，近靠控制delta_x和delta_y，可能得到的结果不是很理想。

*/

float y(float x)
{
  return x*x*x + x*x + 1;
}

float func(float x1,float x2)
{
  if (y(x1)*y(x2) > 0) return 0;
  else if (sqrt( ( y(x1)-y(x2) )*(y(x1)-y(x2) ) ) < 0.0001) return (x1+x2) / 2;
  return func(x1,(x1+x2)/2) + func((x1+x2)/2,x2);
}

int main(void)
{
  float x1 = -100.0;
  float x2 = 100.0;
  float x = func(x1,x2);
  printf("%f\n",x);
  return 0;
}

