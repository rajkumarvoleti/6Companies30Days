// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  int maxProfit(int maxTrans, int N, int prices[])
  {
    // code here
    int size = N;
    int dp[size][maxTrans + 1][2];
    dp[0][0][0] = 0;
    dp[0][0][1] = -prices[0];
    for (int i = 1; i < size; i++)
    {
      dp[i][0][0] = 0;
      dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - prices[i]);
    }
    for (int j = 1; j <= maxTrans; j++)
    {
      dp[0][j][0] = 0;
      dp[0][j][1] = -prices[0];
      for (int i = 1; i < size; i++)
      {
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i]);
        dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i]);
      }
    }
    return dp[size - 1][maxTrans][0];
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N, K;
    cin >> K;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
      cin >> A[i];

    Solution ob;
    cout << ob.maxProfit(K, N, A) << endl;
  }
  return 0;
} // } Driver Code Ends