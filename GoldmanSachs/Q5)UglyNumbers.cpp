// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
  // #define ull unsigned long long
  /* Function to get the nth ugly number*/
  ull getNthUglyNo(int n)
  {
    // code here
    ull i = 0, j = 0, k = 0;
    vector<ull> ans;
    ans.push_back(1);
    while (ans.size() < n)
    {
      ull x = ans[i] * 2;
      ull y = ans[j] * 3;
      ull z = ans[k] * 5;
      ull mini = min(x, min(y, z));
      ans.push_back(mini);
      if (mini == x)
        i++;
      if (mini == y)
        j++;
      if (mini == z)
        k++;
    }
    return ans[n - 1];
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
    Solution ob;
    auto ans = ob.getNthUglyNo(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends