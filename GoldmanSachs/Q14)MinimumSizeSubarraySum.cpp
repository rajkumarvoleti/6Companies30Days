#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int size = nums.size();
    int sum_arr[size + 1];
    sum_arr[0] = 0;
    for (int i = 0; i < size; i++)
      sum_arr[i + 1] = sum_arr[i] + nums[i];

    int i = 0, j = 1, ans = INT_MAX;
    while (j <= size)
    {
      int sum = sum_arr[j] - sum_arr[i];
      if (sum < target)
        j++;
      if (sum >= target)
      {
        ans = min(ans, j - i);
        i++;
      }
    }
    if (ans == INT_MAX)
      return 0;
    return ans;
  }
};

int main()
{
  return 0;
}