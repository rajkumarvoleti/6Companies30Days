#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dp[501][501];

  int solve(vector<int> &piles, int i, int j)
  {
    int size = piles.size();
    if (i >= size || j < 0 || i > j)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    int left = piles[i] + min(solve(piles, i + 2, j), solve(piles, i + 1, j - 1));
    int right = piles[j] + min(solve(piles, i + 1, j - 1), solve(piles, i, j - 2));
    return dp[i][j] = max(left, right);
  }

  bool stoneGame(vector<int> &piles)
  {
    int totalSum = 0;
    int size = piles.size();
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < size; i++)
      totalSum += piles[i];

    int sum = solve(piles, 0, size - 1);
    return sum > totalSum - sum;
  }
};