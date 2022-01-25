#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isOkay(vector<int> &piles, int h, int mid)
  {
    if (mid == 0)
      return false;
    int count = 0;
    for (int i = 0; i < piles.size(); i++)
    {
      count += ceil((double)(piles[i]) / mid);
    }
    return count <= h;
  }

  int minEatingSpeed(vector<int> &piles, int h)
  {
    int start = 0, end = 1e9 + 1;
    while (start < end)
    {
      int mid = (start + end) / 2;
      if (isOkay(piles, h, mid))
        end = mid;
      else
        start = mid + 1;
    }
    return start;
  }
};