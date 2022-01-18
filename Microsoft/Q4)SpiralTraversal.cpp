// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // Function to return a list of integers denoting spiral traversal of matrix.
  vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
  {
    // code here
    vector<int> ans;
    int i = 0, j = 0;
    while (i < r && j < c)
    {
      if (i < r && j < c)
      {
        for (int k = j; k < c; k++)
          ans.push_back(matrix[i][k]);
        i++;
      }
      if (i < r && j < c)
      {
        for (int k = i; k < r; k++)
          ans.push_back(matrix[k][c - 1]);
        c--;
      }
      if (i < r && j < c)
      {
        for (int k = c - 1; k >= j; k--)
          ans.push_back(matrix[r - 1][k]);
        r--;
      }
      if (i < r && j < c)
      {
        for (int k = r - 1; k >= i; k--)
          ans.push_back(matrix[k][j]);
        j++;
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
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r);

    for (int i = 0; i < r; i++)
    {
      matrix[i].assign(c, 0);
      for (int j = 0; j < c; j++)
      {
        cin >> matrix[i][j];
      }
    }

    Solution ob;
    vector<int> result = ob.spirallyTraverse(matrix, r, c);
    for (int i = 0; i < result.size(); ++i)
      cout << result[i] << " ";
    cout << endl;
  }
  return 0;
} // } Driver Code Ends