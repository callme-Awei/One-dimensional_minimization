#pragma once
#define EPS 1e-10
#include "Function.h"
class Fibonacce {
public:
  Fibonacce(double a_, double b_, double eps_, Function &f_);
  void Solve();
  intrvl_t GetRes();

private:
  int Fib_n(int n);
  Function &f;
  double a;
  double b;
  double eps;

  double aRes;
  double bRes;
  int fCount;
  int iCount;
};