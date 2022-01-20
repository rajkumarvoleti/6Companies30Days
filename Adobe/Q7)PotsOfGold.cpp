// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  int dp[501][501];

  int solve(vector<int> &A, int n, int i, int j)
  {
    if (i >= n || j < 0 || i > j)
      return 0;
    if (i == j)
      return A[i];
    if (dp[i][j] != -1)
      return dp[i][j];

    int takeFirst = min(solve(A, n, i + 2, j), solve(A, n, i + 1, j - 1)) + A[i];
    int takeLast = min(solve(A, n, i + 1, j - 1), solve(A, n, i, j - 2)) + A[j];
    return dp[i][j] = max(takeFirst, takeLast);
  }

  int maxCoins(vector<int> &A, int n)
  {
    // Write your code here
    dp[n][n];
    memset(dp, -1, sizeof(dp));
    return solve(A, n, 0, n - 1);
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
      cin >> A[i];
    }
    Solution ob;
    cout << ob.maxCoins(A, N) << "\n";
  }
  return 0;
}
// } Driver Code Ends