
#include <iostream>
#include <iomanip>
#include <math.h>

#define f(x) pow(x, x) - 100

using namespace std;

int main()
{
  /* Declaring required variables */
  float x0, x1, x, f0, f1, f, e;
  int step = 1;
  int loop;

  /* Setting precision and writing floating point values in fixed-point notation. */
  cout << setprecision(6) << fixed;

/* Inputs */
up:
  cout << "Masukan Nilai x[1]: ";
  cin >> x0;
  cout << "Masukan Nilai x[2]: ";
  cin >> x1;
  cout << "Nilai yang dicari (default x = 0): ";
  cin >> e;
  cout << "Masukan banyak Iterasi ";
  cin >> loop;

  /* Calculating Functional Value */
  f0 = f(x0);
  f1 = f(x1);

  /* Checking whether given guesses brackets the root or not. */
  if (f0 * f1 > 0.0)
  {
    cout << "Incorrect Initial Guesses." << f0 << endl;
    goto up;
  }
  /* Implementing Bisection Method */
  cout << endl
       << "****************" << endl;
  cout << "Bisection Method" << endl;
  cout << "Author By : " << endl;
  cout << "Robby Ulung Pambudi (5025211042)" << endl;
  cout << "Hanafi Satriyo Utomo Setiawan (5025211195)" << endl;
  cout << "Sandyatama Fransisna Nugraha (5025211196)" << endl;
  cout
      << "****************" << endl;
  do
  {
    /* Bisecting Interval */
    x = (x0 + x1) / 2;
    f = f(x);

    cout << "Iteration-" << step << "\tx3 = " << setw(10) << x << " and f(x3) = " << setw(10) << f(x) << endl;

    if (f0 * f < 0)
    {
      x1 = x;
    }
    else
    {
      x0 = x;
    }
    cout << "Nilai\tx1 = " << x1 << "\t f(x1) = " << f(x1) << endl;
    cout << "Nilai\tx2 = " << x0 << "\t f(x2) = " << f(x0) << endl;
    cout << endl;
    step = step + 1;
  } while (--loop);

  cout << endl
       << "Root is : " << x << endl;

  return 0;
}
