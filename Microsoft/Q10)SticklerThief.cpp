// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
public:
  // Function to find the maximum money the thief can get.

  int dp[10001];

  int solve(int arr[], int n, int pos)
  {
    if (pos >= n)
      return 0;
    if (dp[pos] != -1)
      return dp[pos];
    int takeIt = arr[pos] + solve(arr, n, pos + 2);
    int leaveIt = solve(arr, n, pos + 1);
    return dp[pos] = max(takeIt, leaveIt);
  }

  int FindMaxSum(int arr[], int n)
  {
    // Your code here
    dp[n];
    memset(dp, -1, sizeof(dp));
    return solve(arr, n, 0);
  }
};

// { Driver Code Starts.
int main()
{
  // taking total testcases
  int t;
  cin >> t;
  while (t--)
  {
    // taking number of houses
    int n;
    cin >> n;
    int a[n];

    // inserting money of each house in the array
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    Solution ob;
    // calling function FindMaxSum()
    cout << ob.FindMaxSum(a, n) << endl;
  }
  return 0;
}
// } Driver Code Ends