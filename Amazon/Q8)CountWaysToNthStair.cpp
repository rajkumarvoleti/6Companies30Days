// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // Function to count number of ways to reach the nth stair
  // when order does not matter.

  long long countWays(int m)
  {
    int n = m / 2;
    long long count = n + 1;
    return count;
  }
};

// { Driver Code Starts.
int main()
{
  // taking count of testcases
  int t;
  cin >> t;

  while (t--)
  {
    // taking stair count
    int m;
    cin >> m;
    Solution ob;
    cout << ob.countWays(m) << endl; // Print the output from our pre computed array
  }
  return 0;
} // } Driver Code Ends