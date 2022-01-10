#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestMountain(vector<int> &arr)
  {
    int size = arr.size();
    int i = 1;
    int ans = 0;
    while (i < size)
    {
      int prev = arr[i - 1];
      int lcount = 0;
      while (i < size && arr[i] > prev)
      {
        lcount++;
        prev = arr[i];
        i++;
      }
      if (lcount == 0)
      {
        i++;
        continue;
      }
      int rcount = 0;
      while (i < size && arr[i] < prev)
      {
        rcount++;
        prev = arr[i];
        i++;
      }
      if (rcount == 0)
      {
        i++;
        continue;
      }
      ans = max(ans, lcount + rcount + 1);
    }
    return ans;
  }
};

int main()
{
  return 0;
}