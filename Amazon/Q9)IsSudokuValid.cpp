// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isValid(vector<vector<int>> mat)
    {
        // code here
        bool row[9][9] = {0}, col[9][9] = {0}, box[3][3][9] = {0};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (mat[i][j] == 0)
                    continue;
                int num = mat[i][j] - 1;
                if (row[i][num] == 1 || col[j][num] == 1 || box[i / 3][j / 3][num] == 1)
                    return false;
                row[i][num] = 1;
                col[j][num] = 1;
                box[i / 3][j / 3][num] = 1;
            }
        }
        return true;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for (int i = 0; i < 81; i++)
            cin >> mat[i / 9][i % 9];

        Solution ob;
        cout << ob.isValid(mat) << "\n";
    }
    return 0;
} // } Driver Code Ends