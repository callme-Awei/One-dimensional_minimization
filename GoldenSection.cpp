#include "GoldenSection.h"
GoldenSection::GoldenSection(double a_, double b_, double eps_, Function &f_) : f(f_)
{
  a = a_;
  b = b_;
  eps = eps_;
}
void GoldenSection::Solve() {
  double alpha = ((3.0 - sqrt(5.0)) / 2.0);
  double lambda = a + alpha * (b - a);
  double mu = b - alpha * (b - a);
  f.ResetRequestCnt();
  if (fabs(a - b) < eps) {
    aRes = a;
    bRes = b;
    iCount = f.GetRequestCnt();
    return; 
  } 
  //В счетчике количества обращений к функции будут учитываться два начальных
  double y1 = f.getVal(lambda);
  double y2 = f.getVal(mu);
  iCount = 0;
  do
  {
    iCount++;
    if (y1 > y2)
    {
      a = lambda;
      lambda = mu;
      if (fabs(a - b) <= eps)
        break;
      mu = b - alpha * (b - a);
      y1 = y2;
      y2 = f.getVal(mu);
    }
    else
    {
      b = mu;
      mu = lambda;
      if (fabs(a - b) <= eps)
        break;
      lambda = a + alpha * (b - a);
      y2 = y1;
      y1 = f.getVal(lambda);
    }
  } while (true);  
  aRes = a;
  bRes = b;
  fCount = f.GetRequestCnt();
}

intrvl_t GoldenSection::GetRes()
{
  intrvl_t res = { aRes, bRes , fCount, iCount};
  return res;
}
