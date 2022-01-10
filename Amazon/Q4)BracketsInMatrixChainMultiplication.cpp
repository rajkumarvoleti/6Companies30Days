// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  string matrixChainOrder(int p[], int n)
  {
    // code here
    pair<int, string> dp[n][n];
    for (int i = 1; i < n; i++)
    {
      dp[i][i].first = 0;
      dp[i][i].second = 'A' + i - 1;
    }
    for (int i = 1; i < n - 1; i++)
    {
      dp[i][i + 1].first = p[i - 1] * p[i] * p[i + 1];
      char mat1 = 'A' + i - 1;
      char mat2 = 'A' + i;
      dp[i][i + 1].second.push_back('(');
      dp[i][i + 1].second.push_back(mat1);
      dp[i][i + 1].second.push_back(mat2);
      dp[i][i + 1].second.push_back(')');
    }

    for (int i = 3; i < n; i++)
    {
      for (int j = 1; j + i - 1 < n; j++)
      {
        int left = j, right = j + i - 1;
        int ans = INT_MAX;
        for (int k = left; k <= right - 1; k++)
        {
          int temp = dp[left][k].first + dp[k + 1][right].first + (p[left - 1] * p[k] * p[right]);
          if (temp < ans)
          {
            string str = "";
            str.push_back('(');
            str += dp[left][k].second + dp[k + 1][right].second;
            str.push_back(')');
            dp[left][right].first = temp;
            dp[left][right].second = str;
            ans = temp;
          }
        }
      }
    }

    // for (int i = 1; i < n; i++)
    // {
    //   for (int j = 1; j <= i; j++)
    //   {
    //     cout << j << " " << i << dp[j][i].second << endl;
    //   }
    // }

    return dp[1][n - 1].second;
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
      cin >> p[i];

    Solution ob;
    cout << ob.matrixChainOrder(p, n) << "\n";
  }
  return 0;
} // } Driver Code Ends