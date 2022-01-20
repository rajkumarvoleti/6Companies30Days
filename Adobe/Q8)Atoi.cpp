// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
  /*You are required to complete this method */
  int atoi(string str)
  {
    // Your code here
    int ans = 0;
    bool isNegative = false;
    if (str[0] == '-')
    {
      isNegative = true;
      str = str.substr(1, str.length() - 1);
    }
    for (int i = 0; i < str.length(); i++)
    {
      int num = str[i] - '0';
      if (num < 0 || num > 9)
        return -1;
      ans = (ans * 10) + num;
    }
    if (isNegative)
      ans = -ans;
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
    cout << ob.atoi(s) << endl;
  }
} // } Driver Code Ends