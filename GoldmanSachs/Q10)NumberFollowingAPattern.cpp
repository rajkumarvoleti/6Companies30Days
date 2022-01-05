// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  string printMinNumberForPattern(string S)
  {
    // code here
    string ans = "1";
    char count = '1';
    int size = S.length(), i = 0;
    while (i < size)
    {
      if (S[i] == 'I')
      {
        count++;
        ans.push_back(count);
        i++;
        continue;
      }
      int j = i;
      while (i < size && S[i] == 'D')
      {
        count++;
        ans.push_back(count);
        i++;
      }
      reverse(ans.begin() + j, ans.begin() + i + 1);
    }
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
    string S;
    cin >> S;
    Solution ob;
    cout << ob.printMinNumberForPattern(S) << endl;
  }
  return 0;
}
// } Driver Code Ends