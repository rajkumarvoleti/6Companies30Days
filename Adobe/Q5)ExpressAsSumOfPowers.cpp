// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
  long long dp[1001][1001];

  long long solve(int num, int power, int i)
  {
    if (num < 0)
      return 0;
    if (num == 0)
      return 1;
    if (dp[num][i] != -1)
      return dp[num][i];
    if (pow(i, power) > num)
      return 0;
    long long sub = pow(i, power);
    return dp[num][i] = solve(num - sub, power, i + 1) + solve(num, power, i + 1);
  }

  long long numOfWays(int n, int x)
  {
    // code here
    dp[n + 1][n + 1];
    memset(dp, -1, sizeof(dp));
    return solve(n, x, 1);
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, x;
    cin >> n >> x;
    Solution ob;
    cout << ob.numOfWays(n, x) << endl;
  }
  return 0;
}
// } Driver Code Ends