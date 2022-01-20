// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
  string nextPalin(string N)
  {
    // complete the function here
    int size = N.length();
    int reqSize = size / 2;
    string c = "";
    if (size % 2 == 1)
      c = N[size / 2];
    string sub = N.substr(0, reqSize);
    if (next_permutation(sub.begin(), sub.end()))
    {
      string ans = sub + c;
      reverse(sub.begin(), sub.end());
      ans += sub;
      return ans;
    }
    return "-1";
  }
};

// { Driver Code Starts.

int main()
{

  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.nextPalin(s) << endl;
  }
  return 0;
} // } Driver Code Ends