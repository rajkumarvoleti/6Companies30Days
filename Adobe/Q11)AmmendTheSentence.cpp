// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  bool isCapital(char c)
  {
    return c >= 65 && c <= 90;
  }

  string amendSentence(string s)
  {
    // your code here
    string ans = "";
    int start = 0;
    if (isCapital(s[0]))
      s[0] += 32;
    for (int i = 1; i < s.length(); i++)
    {
      if (isCapital(s[i]))
      {
        s[i] += 32;
        ans += s.substr(start, i - start) + " ";
        start = i;
      }
    }
    ans += s.substr(start, s.length() - start);
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
    string s;
    cin >> s;
    Solution ob;
    cout << ob.amendSentence(s) << endl;
  }
} // } Driver Code Ends