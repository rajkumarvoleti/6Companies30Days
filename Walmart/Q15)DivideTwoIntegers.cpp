#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int divide(int dividend, int divisor)
  {
    if (abs(dividend) < abs(divisor))
      return 0;
    if (divisor == -1)
      return dividend == INT_MIN ? INT_MAX : 0 - dividend;

    bool dividendNeg = dividend < 0;
    bool divisorNeg = divisor < 0;

    if ((dividendNeg && divisorNeg) || (!dividendNeg && !divisorNeg))
    {
      return 1 + divide(dividend - divisor, divisor);
    }
    else
    {
      return -1 + divide(dividend + divisor, divisor);
    }
  }
};