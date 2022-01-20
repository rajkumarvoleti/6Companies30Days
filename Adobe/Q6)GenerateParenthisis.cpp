// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);

// } Driver Code Ends
// User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{

  void solve(int stkCount, vector<string> &ans, int size, int i, string str)
  {
    if (i == size)
    {
      if (stkCount == 0)
        ans.push_back(str);
      return;
    }
    if (stkCount * 2 > size)
      return;
    // add open bracket
    stkCount++;
    solve(stkCount, ans, size, i + 1, str + "(");
    stkCount--;
    // add closed bracket
    if (stkCount == 0)
      return;
    stkCount--;
    solve(stkCount, ans, size, i + 1, str + ")");
  }

public:
  vector<string> AllParenthesis(int n)
  {
    // Your code goes here
    int stkCount = 0;
    vector<string> ans;
    solve(stkCount, ans, 2 * n, 0, "");
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
    int n;
    cin >> n;
    Solution ob;
    vector<string> result = ob.AllParenthesis(n);
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); ++i)
      cout << result[i] << "\n";
  }
  return 0;
}
// } Driver Code Ends