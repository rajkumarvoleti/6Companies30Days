// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
  int lengthOfLongestAP(int A[], int n)
  {
    // code here
    vector<vector<int>> vect(n, vector<int>(A[n - 1] - A[0] + 1, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int diff = A[j] - A[i];
        vect[j][diff] = vect[i][diff] + 1;
      }
    }
    int maxi = 0;
    for (int i = 0; i < vect.size(); i++)
    {
      for (int j = 0; j < vect[i].size(); j++)
      {
        maxi = max(maxi, vect[i][j]);
      }
    }
    return maxi + 1;
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
    int A[n];
    for (int i = 0; i < n; i++)
    {
      cin >> A[i];
    }
    Solution ob;
    auto ans = ob.lengthOfLongestAP(A, n);
    cout << ans << "\n";
  }
  return 0;
} // } Driver Code Ends