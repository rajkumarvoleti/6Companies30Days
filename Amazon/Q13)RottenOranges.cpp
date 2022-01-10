#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    int min = 1;
    bool found = false;
    while (1)
    {
      found = false;
      vector<vector<int>> newGrid = grid;
      for (int i = 0; i < grid.size(); i++)
      {
        for (int j = 0; j < grid[i].size(); j++)
        {
          if (grid[i][j] == 0 || grid[i][j] == 1)
            continue;
          if (i - 1 >= 0 && grid[i - 1][j] == 1)
          {
            newGrid[i - 1][j] = 2;
            found = true;
          }
          if (i + 1 < grid.size() && grid[i + 1][j] == 1)
          {
            newGrid[i + 1][j] = 2;
            found = true;
          }
          if (j - 1 >= 0 && grid[i][j - 1] == 1)
          {
            newGrid[i][j - 1] = 2;
            found = true;
          }
          if (j + 1 < grid[i].size() && grid[i][j + 1] == 1)
          {
            newGrid[i][j + 1] = 2;
            found = true;
          }
        }
      }
      grid = newGrid;
      if (!found)
      {
        for (int i = 0; i < grid.size(); i++)
        {
          for (int j = 0; j < grid[i].size(); j++)
          {
            if (grid[i][j] == 1)
              return -1;
          }
        }
        return min - 1;
      }
      min++;
    }
    return min;
  }
};

int main()
{
  return 0;
}