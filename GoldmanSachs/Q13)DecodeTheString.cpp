// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  string decodedString(string s)
  {
    // code here
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] != ']')
      {
        stk.push(s[i]);
        continue;
      }
      string temp = "";
      while (stk.top() != '[')
      {
        temp.push_back(stk.top());
        stk.pop();
      }
      stk.pop();
      string tempNum = "";
      while (!stk.empty())
      {
        if (stk.top() >= '0' && stk.top() <= '9')
        {
          tempNum.push_back(stk.top());
          stk.pop();
        }
        else
          break;
      }
      reverse(tempNum.begin(), tempNum.end());
      int num = stoi(tempNum);
      reverse(temp.begin(), temp.end());
      while (num--)
      {
        for (int i = 0; i < temp.length(); i++)
        {
          stk.push(temp[i]);
        }
      }
    }
    string ans = "";
    while (!stk.empty())
    {
      ans.push_back(stk.top());
      stk.pop();
    }
    reverse(ans.begin(), ans.end());
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
    cout << ob.decodedString(s) << "\n";
  }
  return 0;
} // } Driver Code Ends