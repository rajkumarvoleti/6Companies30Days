#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxDistance(vector<vector<int>> &grid)
  {
    queue<pair<int, int>> q;
    bool flag = false;
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[i].size(); j++)
      {
        if (grid[i][j] == 0)
        {
          flag = true;
          continue;
        }
        q.push({i, j});
      }
    }
    if (q.empty() || !flag)
      return -1;

    while (!q.empty())
    {
      pair<int, int> top = q.front();
      q.pop();
      // up
      if (top.first - 1 >= 0 && grid[top.first - 1][top.second] == 0)
      {
        grid[top.first - 1][top.second] = grid[top.first][top.second] + 1;
        q.push({top.first - 1, top.second});
      }

      // down
      if (top.first + 1 < grid.size() && grid[top.first + 1][top.second] == 0)
      {
        grid[top.first + 1][top.second] = grid[top.first][top.second] + 1;
        q.push({top.first + 1, top.second});
      }
      // left
      if (top.second - 1 >= 0 && grid[top.first][top.second - 1] == 0)
      {
        grid[top.first][top.second - 1] = grid[top.first][top.second] + 1;
        q.push({top.first, top.second - 1});
      }
      // right
      if (top.second + 1 < grid[0].size() && grid[top.first][top.second + 1] == 0)
      {
        grid[top.first][top.second + 1] = grid[top.first][top.second] + 1;
        q.push({top.first, top.second + 1});
      }
    }
    int maxi = 1;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[i].size(); j++)
      {
        maxi = max(maxi, grid[i][j]);
      }
    }
    return maxi - 1;
  }
};