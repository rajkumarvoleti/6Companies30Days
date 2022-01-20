// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define N 1000

// } Driver Code Ends
// you are required to complete this function
// function should print the required range
typedef pair<int, int> pi;

class Solution
{
public:
  pair<int, int> findSmallestRange(int arr[][N], int n, int k)
  {
    // code here
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < k; i++)
    {
      pq.push({arr[i][0], i});
      mini = min(mini, arr[i][0]);
      maxi = max(maxi, arr[i][0]);
    }
    pair<int, int> ans = {mini, maxi};
    int diff = maxi - mini;
    int count[k] = {0};
    while (!pq.empty())
    {
      pi top = pq.top();
      pq.pop();
      count[top.second]++;
      if (count[top.second] >= n)
        break;
      pq.push({arr[top.second][count[top.second]], top.second});
      mini = pq.top().first;
      maxi = max(maxi, arr[top.second][count[top.second]]);
      if (diff > maxi - mini)
      {
        diff = maxi - mini;
        ans = {mini, maxi};
      }
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
    int n, k;
    cin >> n >> k;
    int arr[N][N];
    pair<int, int> rangee;
    for (int i = 0; i < k; i++)
      for (int j = 0; j < n; j++)
        cin >> arr[i][j];
    Solution obj;
    rangee = obj.findSmallestRange(arr, n, k);
    cout << rangee.first << " " << rangee.second << "\n";
  }
  return 0;
}

// } Driver Code Ends