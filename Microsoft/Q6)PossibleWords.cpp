// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
  vector<string> helper = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
  // Function to find list of all words possible by pressing given numbers.

  void solve(int a[], int N, int pos, vector<string> &ans, string str)
  {
    if (pos >= N)
    {
      ans.push_back(str);
      return;
    }
    int charPos = a[pos];
    for (int i = 0; i < helper[charPos].size(); i++)
    {
      solve(a, N, pos + 1, ans, str + helper[charPos][i]);
    }
  }

  vector<string> possibleWords(int a[], int N)
  {
    // Your code here
    vector<string> ans;
    solve(a, N, 0, ans, "");
    sort(ans.begin(), ans.end());
    return ans;
  }
};

// { Driver Code Starts.

int main()
{

  int T;

  cin >> T; // testcases

  while (T--)
  { // while testcases exist
    int N;

    cin >> N; // input size of array

    int a[N]; // declare the array

    for (int i = 0; i < N; i++)
    {
      cin >> a[i]; // input the elements of array that are keys to be pressed
    }

    Solution obj;

    vector<string> res = obj.possibleWords(a, N);
    for (string i : res)
      cout << i << " ";
    cout << endl;
  }

  return 0;
} // } Driver Code Ends