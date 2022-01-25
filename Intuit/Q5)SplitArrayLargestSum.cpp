#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isOk(vector<int> &nums, int reqSum, int m)
  {
    int count = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > reqSum)
        return false;
      if (sum + nums[i] <= reqSum)
        sum += nums[i];
      else
      {
        count++;
        sum = nums[i];
      }
    }
    count++;
    return count <= m;
  }

  int splitArray(vector<int> &nums, int m)
  {
    int start = 0, end = (int)1e9 + 1;
    int mid;
    while (start < end)
    {
      mid = (start + end) / 2;
      if (isOk(nums, mid, m))
        end = mid;
      else
      {
        start = mid + 1;
      }
    }
    return start;
  }
};