#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isOk(vector<int> &weights, int days, int mid)
  {
    int sum = 0, count = 0;
    for (int i = 0; i < weights.size(); i++)
    {
      if (weights[i] > mid)
        return false;
      if (sum + weights[i] <= mid)
        sum += weights[i];
      else
      {
        sum = weights[i];
        count++;
      }
    }
    count++;
    return count <= days;
  }

  int shipWithinDays(vector<int> &weights, int days)
  {
    int start = 0, end = 1e9 + 1;
    while (start < end)
    {
      int mid = (start + end) / 2;
      if (isOk(weights, days, mid))
        end = mid;
      else
        start = mid + 1;
    }
    return start;
  }
};