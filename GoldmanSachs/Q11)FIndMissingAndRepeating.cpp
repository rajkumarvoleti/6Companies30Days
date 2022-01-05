// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
  int *findTwoElement(int *arr, int n)
  {
    // code here
    int *ans = new int[2];
    for (int i = 0; i < n; i++)
    {
      int pos = abs(arr[i]) - 1;
      if (arr[pos] < 0)
        ans[0] = pos + 1;
      else
        arr[pos] *= -1;
    }
    for (int i = 0; i < n; i++)
    {
      if (arr[i] > 0)
        ans[1] = i + 1;
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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    Solution ob;
    auto ans = ob.findTwoElement(a, n);
    cout << ans[0] << " " << ans[1] << "\n";
  }
  return 0;
} // } Driver Code Ends