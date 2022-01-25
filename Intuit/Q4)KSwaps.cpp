// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // Function to find the largest number after k swaps.
  string findMaximumNum(string &str, int k)
  {
    // code here.
    int size = str.length();
    if (k <= 0)
      return str;
    string ans = str;
    for (int i = 0; i < size; i++)
    {
      for (int j = i + 1; j < size; j++)
      {
        if (str[i] >= str[j])
          continue;
        swap(str[i], str[j]);
        string temp = findMaximumNum(str, k - 1);
        swap(str[i], str[j]);
        ans = max(ans, temp);
      }
    }
    return ans;
  }
};

// { Driver Code Starts.

int main()
{
  int t, k;
  string str;

  cin >> t;
  while (t--)
  {
    cin >> k >> str;
    Solution ob;
    cout << ob.findMaximumNum(str, k) << endl;
  }
  return 0;
}
// } Driver Code Ends