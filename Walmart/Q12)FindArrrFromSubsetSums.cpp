#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void solve(vector<int> &sums, vector<int> &ans)
  {
    int size = sums.size();
    if (size < 2)
      return;
    vector<int> excluded, included;
    unordered_map<int, int> Map;
    int diff = sums[size - 1] - sums[size - 2];

    if (size == 2)
    {
      if (sums[0] != 0 && sums[1] != 0)
        ans.push_back(diff);
      else if (sums[0] == 0)
        ans.push_back(sums[1]);
      else
        ans.push_back(sums[0]);
      return;
    }

    for (int i = 0; i < size; i++)
      Map[sums[i]]++;

    if (diff == 0)
    {
      int i = 0;
      while (i < size)
      {
        excluded.push_back(sums[i]);
        i += 2;
      }
      ans.push_back(0);
      return solve(excluded, ans);
    }

    for (int i = 0; i < size; i++)
    {
      if (Map[sums[i]] <= 0)
        continue;
      Map[sums[i]]--;

      bool searchIt = binary_search(sums.begin(), sums.end(), sums[i] + diff);
      if (searchIt)
      {
        excluded.push_back(sums[i]);
        included.push_back(sums[i] + diff);
        Map[sums[i] + diff]--;
      }
      else
        included.push_back(sums[i]);
    }
    for (int i = 0; i < size / 2; i++)
    {
      if (excluded[i] == 0)
      {
        ans.push_back(diff);
        return solve(excluded, ans);
      }
    }
    ans.push_back(diff * -1);
    return solve(included, ans);
  }

  vector<int> recoverArray(int n, vector<int> &sums)
  {
    sort(sums.begin(), sums.end());
    vector<int> ans;
    solve(sums, ans);
    return ans;
  }
};