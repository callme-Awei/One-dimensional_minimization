#include "Dichotomy.h"
Dichotomy::Dichotomy(double a_, double b_, double eps_, Function &f_) : f(f_)
{
  a = a_;
  b = b_;
  eps = eps_;
}
void Dichotomy::Solve() {
  double med;
  double y1;
  double y2;
  f.ResetRequestCnt();
  int k = 0;
  do
  {
    k++;
    med = (a + b) / 2.0;
    y1 = f.getVal(med - eps);
    y2 = f.getVal(med + eps);
    if (y1 < y2){
      b = med;
    }
    else{
      a = med;
    }
  }while ((b - a) > eps);
  aRes = a;
  bRes = b;
  fCount = f.GetRequestCnt();
  iCount = k;
}

intrvl_t Dichotomy::GetRes()
{
  intrvl_t res = { aRes, bRes , fCount, iCount };
  return res;
}
