// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // Function to calculate the span of stockâ€™s price for all n days.
  vector<int> calculateSpan(int price[], int n)
  {
    // Your code here
    stack<int> stk;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
      if (stk.empty())
      {
        stk.push(i);
        ans[i] = 1;
        continue;
      }
      int count = 1;
      while (!stk.empty() && price[stk.top()] <= price[i])
      {
        int top = stk.top();
        stk.pop();
        count += ans[top];
      }
      stk.push(i);
      ans[i] = count;
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
    int i, a[n];
    for (i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    Solution obj;
    vector<int> s = obj.calculateSpan(a, n);

    for (i = 0; i < n; i++)
    {
      cout << s[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends