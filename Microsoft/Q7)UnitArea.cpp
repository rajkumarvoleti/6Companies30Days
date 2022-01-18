// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  int solve(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int rows, int cols)
  {
    if (i < 0 || j < 0 || i >= rows || j >= cols)
      return 0;
    if (grid[i][j] == 0 || visited[i][j])
      return 0;
    visited[i][j] = true;
    int ul = solve(grid, visited, i - 1, j - 1, rows, cols);
    int u = solve(grid, visited, i - 1, j, rows, cols);
    int ur = solve(grid, visited, i - 1, j + 1, rows, cols);
    int l = solve(grid, visited, i, j - 1, rows, cols);
    int r = solve(grid, visited, i, j + 1, rows, cols);
    int bl = solve(grid, visited, i + 1, j - 1, rows, cols);
    int b = solve(grid, visited, i + 1, j, rows, cols);
    int br = solve(grid, visited, i + 1, j + 1, rows, cols);
    int sum = ul + u + ur + l + r + bl + b + br + 1;
    return sum;
  }

  // Function to find unit area of the largest region of 1s.
  int findMaxArea(vector<vector<int>> &grid)
  {
    // Code here
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int ans = 0;
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        int temp = solve(grid, visited, i, j, rows, cols);
        ans = max(ans, temp);
      }
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> grid[i][j];
      }
    }
    Solution obj;
    int ans = obj.findMaxArea(grid);
    cout << ans << "\n";
  }
  return 0;
} // } Driver Code Ends