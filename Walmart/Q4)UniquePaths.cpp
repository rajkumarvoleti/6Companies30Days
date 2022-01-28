// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
  // Function to find total number of unique paths.

  int solve(int i, int j, int a, int b)
  {
    if (i > a || j > b)
      return 0;
    if (i == a && j == b)
      return 1;

    return solve(i + 1, j, a, b) + solve(i, j + 1, a, b);
  }

  int NumberOfPath(int a, int b)
  {
    // code here
    return solve(1, 1, a, b);
  }
};

// { Driver Code Starts.
int main()
{
  // taking total testcases
  int t;
  cin >> t;
  while (t--)
  {
    // taking dimensions of the matrix
    int a, b;
    cin >> a >> b;
    Solution ob;
    // calling NumberOfPath() function
    cout << ob.NumberOfPath(a, b) << endl;
  }
}

// } Driver Code Ends