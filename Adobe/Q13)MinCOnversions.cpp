// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  int lis(vector<int> vect)
  {
    int size = vect.size();
    int dp[size + 1];
    dp[0] = INT_MIN;
    for (int i = 1; i <= size; i++)
      dp[i] = INT_MAX;

    for (int i = 0; i < size; i++)
    {
      int pos = upper_bound(dp, dp + size + 1, vect[i]) - dp;
      if (dp[pos - 1] < vect[i])
        dp[pos] = vect[i];
    }
    for (int i = size; i >= 0; i--)
    {
      if (dp[i] != INT_MAX)
        return i;
    }
  }

  int minInsAndDel(int A[], int B[], int N, int M)
  {
    // code here
    vector<int> vect;

    for (int i = 0; i < N; i++)
    {
      if (binary_search(B, B + M, A[i]))
      {
        vect.push_back(A[i]);
      }
    }
    int incSeq = lis(vect);

    int ans = 0;
    // cout<<incSeq<<endl;
    ans += N - incSeq; // deleteing
    ans += M - incSeq; // adding;
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
    int N, M;
    cin >> N >> M;

    int A[N], B[M];
    for (int i = 0; i < N; i++)
      cin >> A[i];
    for (int i = 0; i < M; i++)
      cin >> B[i];

    Solution ob;
    cout << ob.minInsAndDel(A, B, N, M) << endl;
  }
  return 0;
} // } Driver Code Ends