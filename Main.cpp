#include <iostream>
#include "GoldenSection.h"
#include "Fibonacce.h"
#include "Function.h"
#include "Dichotomy.h"
#include <string>
#define SIZE 3

using namespace std;
void printResult(intrvl_t Result, double eps, string name)
{
  cout << name << endl;
  cout << "Function calls: " << Result.fcount;
  cout << " Iterations count: " << Result.icount << endl;
  cout << "Interval :[" << Result.a << " ; " << Result.b << "]" << endl; 
  cout << "Epsilon: " << eps << "; Interval length: " << fabs(Result.a - Result.b) << endl;
  cout << "________________________________________" << endl;
}

int main(void)
{
  double Eps[SIZE] = { 0.1, 0.01, 0.001 };
  double a = 1.1;
  double b = 3.5;

  Function f;
  for (int j = 0; j < SIZE; j++)
  {
    intrvl_t Result;
    GoldenSection Gs(a, b, Eps[j], f);
    Gs.Solve();
    Result = Gs.GetRes();
    printResult(Result, Eps[j], "GoldenSection");

    Fibonacce Fib(a, b, Eps[j], f);
    Fib.Solve();
    Result = Fib.GetRes();
    printResult(Result, Eps[j], "Fibonacce");

    Dichotomy Dich(a, b, Eps[j], f);
    Dich.Solve();
    Result = Dich.GetRes();
    printResult(Result, Eps[j], "Dichotomy");
  }
  return 0;
}