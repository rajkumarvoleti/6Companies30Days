// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  long long dp[1001][1001];
  int mod = 1000000007;

  long long solve(int N, int count, int K)
  {
    if (N == 0)
      return 1;
    if (dp[N][count] != -1)
      return dp[N][count] % mod;
    long long consonants = ((solve(N - 1, 0, K) % mod) * 21) % mod;
    long long vowels = count == K ? 0 : ((solve(N - 1, count + 1, K) % mod) * 5) % mod;
    return dp[N][count] = (consonants + vowels) % mod;
  }

  int kvowelwords(int N, int K)
  {
    // Write Your Code here
    if (N == 0)
      return 0;
    dp[N + 1][K + 1];
    memset(dp, -1, sizeof(dp));
    return solve(N, 0, K) % mod;
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
    int K;
    cin >> N >> K;

    Solution ob;
    int ans = ob.kvowelwords(N, K);
    cout << ans << endl;
  }
  return 0;
} // } Driver Code Ends