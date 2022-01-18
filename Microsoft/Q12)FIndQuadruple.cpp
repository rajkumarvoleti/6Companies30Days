// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
  // arr[] : int input array of integers
  // k : the quadruple sum required

  void solve(vector<int> &arr, int i, int j, int p1, int p2, int reqSum, set<vector<int>> &ans)
  {
    if (p1 >= p2)
      return;
    int sum = arr[i] + arr[j] + arr[p1] + arr[p2];
    if (sum > reqSum)
      solve(arr, i, j, p1, p2 - 1, reqSum, ans);
    else if (sum < reqSum)
      solve(arr, i, j, p1 + 1, p2, reqSum, ans);
    else
    {
      ans.insert({arr[i], arr[j], arr[p1], arr[p2]});
      // solve(arr,i,j,p1,p2-1,reqSum,ans);
      solve(arr, i, j, p1 + 1, p2, reqSum, ans);
    }
  }

  vector<vector<int>> fourSum(vector<int> &arr, int k)
  {
    // Your code goes here
    sort(arr.begin(), arr.end());
    set<vector<int>> ans;
    for (int i = 0; i < arr.size() - 3; i++)
    {
      for (int j = i + 1; j < arr.size() - 2; j++)
      {
        int p1 = j + 1, p2 = arr.size() - 1;
        solve(arr, i, j, p1, p2, k, ans);
      }
    }
    vector<vector<int>> vect;
    for (auto &ele : ans)
    {
      vect.push_back(ele);
    }
    return vect;
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, k, i;
    cin >> n >> k;
    vector<int> a(n);
    for (i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    Solution ob;
    vector<vector<int>> ans = ob.fourSum(a, k);
    for (auto &v : ans)
    {
      for (int &u : v)
      {
        cout << u << " ";
      }
      cout << "$";
    }
    if (ans.empty())
    {
      cout << -1;
    }
    cout << "\n";
  }
  return 0;
} // } Driver Code Ends