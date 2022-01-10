// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  string FirstNonRepeating(string A)
  {
    // Code here
    int count[26] = {0};
    int p = 0;
    string ans = "";
    for (int i = 0; i < A.length(); i++)
    {
      int pos = A[i] - 'a';
      count[pos]++;
      char character = '#';
      while (p <= i)
      {
        pos = A[p] - 'a';
        if (count[pos] == 1)
        {
          character = A[p];
          break;
        }
        p++;
      }
      ans.push_back(character);
    }
    return ans;
  }
};

// { Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    string A;
    cin >> A;
    Solution obj;
    string ans = obj.FirstNonRepeating(A);
    cout << ans << "\n";
  }
  return 0;
} // } Driver Code Ends