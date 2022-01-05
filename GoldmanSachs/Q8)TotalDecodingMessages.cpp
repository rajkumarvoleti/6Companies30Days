// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  long long dp[10007];
  int mod = 1e9 + 7;
  int count(string &str, int i)
  {
    int size = str.length();
    if (i == size)
      return 1;
      
    if (dp[i] != 0)
      return dp[i];
    if (str[i] == '0')
      return 0;
    long long count1 = count(str, i + 1) % mod;
    long long count2 = 0;
    if (i + 1 < size)
    {
      int num = stoi(str.substr(i, 2));
      if (num <= 26 && num != 0)
        count2 = count(str, i + 2) % mod;
    }
    return dp[i] = (count1 + count2) % mod;
  }

  int CountWays(string str)
  {
    // Code here
    int size = str.length();
    if (str[0] == '0')
      return 0;
    if (size == 1)
      return 1;
    memset(dp, sizeof(dp), 0);
    return count(str, 0) % mod;
  }
};

// { Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    string str;
    cin >> str;
    Solution obj;
    int ans = obj.CountWays(str);
    cout << ans << "\n";
  }
  return 0;
} // } Driver Code Ends