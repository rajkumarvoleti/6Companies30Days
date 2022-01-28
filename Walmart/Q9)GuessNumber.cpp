#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dp[202][202];

  int solve(int start, int end)
  {
    if (start >= end)
      return 0;
    if (dp[start][end] != -1)
      return dp[start][end];

    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
      int temp = max(solve(start, i - 1), solve(i + 1, end)) + i;
      ans = min(ans, temp);
    }
    return dp[start][end] = ans;
  }

  int getMoneyAmount(int n)
  {
    dp[n + 1][n + 1];
    memset(dp, -1, sizeof(dp));
    return solve(1, n);
  }
};