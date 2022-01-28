// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function Template for C++

bool cmp(pair<string, int> p1, pair<string, int> p2)
{
  return p1.first < p2.first;
}

class Solution
{
public:
  vector<vector<string>> Anagrams(vector<string> &stringList)
  {
    // code here
    unordered_map<string, vector<string>> Map;
    int size = stringList.size();
    for (int i = 0; i < size; i++)
    {
      string str = stringList[i];
      sort(str.begin(), str.end());
      Map[str].push_back(stringList[i]);
    }
    vector<vector<string>> ans;
    for (auto &vect : Map)
      ans.push_back(vect.second);
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
    vector<string> string_list(n);
    for (int i = 0; i < n; ++i)
      cin >> string_list[i];
    Solution ob;
    vector<vector<string>> result = ob.Anagrams(string_list);
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
      for (int j = 0; j < result[i].size(); j++)
      {
        cout << result[i][j] << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}
// } Driver Code Ends