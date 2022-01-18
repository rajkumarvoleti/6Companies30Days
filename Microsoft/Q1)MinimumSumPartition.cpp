// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
  void solve(int arr[], int i, int n, int &ans, int sum, int totalSum, vector<vector<bool>> &visited)
  {
    if (visited[i][sum])
      return;
    visited[i][sum] = true;
    if (2 * sum >= totalSum)
    {
      ans = min(ans, 2 * sum - totalSum);
      return;
    }
    ans = min(ans, totalSum - 2 * sum);
    if (i == n - 1)
      return;
    solve(arr, i + 1, n, ans, sum + arr[i + 1], totalSum, visited);
    solve(arr, i + 1, n, ans, sum, totalSum, visited);
  }

  int minDifference(int arr[], int n)
  {
    // Your code goes here
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += arr[i];
    vector<vector<bool>> visited(n, vector<bool>(sum + 1, 0));
    int ans = INT_MAX;
    solve(arr, 0, n, ans, 0, sum, visited);
    solve(arr, 0, n, ans, arr[0], sum, visited);
    return ans;
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

    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    Solution ob;
    cout << ob.minDifference(a, n) << "\n";
  }
  return 0;
} // } Driver Code Ends