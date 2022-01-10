// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  string colName(long long int n)
  {
    // your code here
    string ans = "";
    if (n <= 26)
    {
      ans += '@' + n;
      return ans;
    }
    n--;
    ans += '@' + (n % 26) + 1;
    return colName(n / 26) + ans;
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long int n;
    cin >> n;
    Solution ob;
    cout << ob.colName(n) << '\n';
  }
}
// } Driver Code Ends