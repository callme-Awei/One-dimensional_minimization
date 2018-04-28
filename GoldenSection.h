#pragma once
#include "Function.h"
class GoldenSection {
public:
  GoldenSection(double a_, double b_, double eps_, Function &f_);
  void Solve();
  intrvl_t GetRes();

private:
  Function &f;
  double a;
  double b;
  double eps;

  double aRes;
  double bRes;
  int fCount;
  int iCount;
};