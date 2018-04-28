#pragma once
#include <math.h>
typedef struct {
  double a;
  double b;
  int fcount;
  int icount;
}intrvl_t;

class Function {
private:
   int requestCnt = 0;
public:
  int GetRequestCnt()
  {
    return requestCnt;
  }

  void ResetRequestCnt()
  {
    requestCnt = 0;
  }

  double getVal(double x)
  {
    requestCnt++;
    double y = x + 2.0 * x / (x * x - 1.0);//Insert yout function here
    return y;
  }
};

