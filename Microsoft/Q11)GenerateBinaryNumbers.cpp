// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to generate binary numbers from 1 to N using a queue.

vector<string> generate(int N)
{
  // Your code here
  vector<string> ans;
  ans.push_back("1");
  N--;
  while (N--)
  {
    bool flag = false;
    string prev = ans[ans.size() - 1];
    for (int i = 0; i < prev.length(); i++)
    {
      if (prev[i] == '0')
      {
        prev[i] = '1';
        flag = true;
        break;
      }
      else
        prev[i] = '0';
    }
    if (!flag)
      prev.push_back('1');
    ans.push_back(prev);
  }
  for (int i = 0; i < ans.size(); i++)
  {
    reverse(ans[i].begin(), ans[i].end());
  }
  return ans;
}

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<string> ans = generate(n);
    for (auto it : ans)
      cout << it << " ";
    cout << endl;
  }
  return 0;
} // } Driver Code Ends