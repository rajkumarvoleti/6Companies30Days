// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  bool isPossible(int arr[], int i, int sum, int reqSum, int N, vector<vector<int>> &dp)
  {
    if (sum == reqSum)
      return true;
    if (i >= N)
      return false;
    if (sum > reqSum)
      return false;
    if (dp[i][sum] != -1)
      return dp[i][sum];
    bool takeIt = isPossible(arr, i + 1, sum + arr[i], reqSum, N, dp);
    bool leaveIt = isPossible(arr, i + 1, sum, reqSum, N, dp);
    return dp[i][sum] = takeIt || leaveIt;
  }

  int equalPartition(int N, int arr[])
  {
    // code here
    int totalSum = 0;
    for (int i = 0; i < N; i++)
      totalSum += arr[i];
    if (totalSum % 2 == 1)
      return false;
    vector<vector<int>> dp(N, vector<int>(totalSum + 1, -1));
    return isPossible(arr, 0, 0, totalSum / 2, N, dp);
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
    int arr[N];
    for (int i = 0; i < N; i++)
      cin >> arr[i];

    Solution ob;
    if (ob.equalPartition(N, arr))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
} // } Driver Code Ends