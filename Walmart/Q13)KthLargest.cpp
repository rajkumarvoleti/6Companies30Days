#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  static bool cmp(string &a, string &b)
  {
    int sizeA = a.length();
    int sizeB = b.length();
    if (sizeA != sizeB)
      return sizeA < sizeB;

    return a < b;
  }

  string kthLargestNumber(vector<string> &nums, int k)
  {
    sort(nums.begin(), nums.end(), cmp);

    int size = nums.size();
    return nums[size - k];
  }
};