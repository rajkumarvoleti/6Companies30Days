// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  bool solve(vector<vector<char>> &board, string &word, int i, int j, int pos, vector<vector<bool>> &visited)
  {
    if (pos == word.length())
      return true;
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
      return false;
    if (visited[i][j])
      return false;
    visited[i][j] = true;

    if (board[i][j] == word[pos])
      pos++;
    else
    {
      visited[i][j] = false;
      return false;
    }

    bool up = solve(board, word, i - 1, j, pos, visited);
    bool down = solve(board, word, i + 1, j, pos, visited);
    bool left = solve(board, word, i, j - 1, pos, visited);
    bool right = solve(board, word, i, j + 1, pos, visited);

    if (up || down || left || right)
      return true;
    else
    {
      visited[i][j] = false;
      return false;
    }
  }

  bool isWordExist(vector<vector<char>> &board, string word)
  {
    // Code here
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++)
    {
      for (int j = 0; j < board[0].size(); j++)
      {
        if (solve(board, word, i, j, 0, visited))
          return true;
      }
    }
    return false;
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
    vector<vector<char>> board(n, vector<char>(m, '*'));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> board[i][j];
    string word;
    cin >> word;
    Solution obj;
    bool ans = obj.isWordExist(board, word);
    if (ans)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
} // } Driver Code Ends