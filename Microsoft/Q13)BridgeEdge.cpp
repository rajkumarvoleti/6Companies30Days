// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // Function to find if the given edge is a bridge in graph.
  int isBridge(int V, vector<int> adj[], int c, int d)
  {
    // Code here
    for (int i = 0; i < adj[c].size(); i++)
    {
      if (adj[c][i] == d)
      {
        adj[c][i] = -1;
        break;
      }
    }
    for (int i = 0; i < adj[d].size(); i++)
    {
      if (adj[d][i] == c)
      {
        adj[d][i] = -1;
        break;
      }
    }

    queue<int> q;
    q.push(c);
    bool visited[V] = {0};
    while (!q.empty())
    {
      int top = q.front();
      q.pop();
      if (top == d)
        return false;
      if (visited[top])
        continue;
      visited[top] = true;
      for (int i = 0; i < adj[top].size(); i++)
      {
        if (adj[top][i] == -1 || visited[adj[top][i]])
          continue;
        q.push(adj[top][i]);
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
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    int i = 0;
    while (i++ < E)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int c, d;
    cin >> c >> d;

    Solution obj;
    cout << obj.isBridge(V, adj, c, d) << "\n";
  }

  return 0;
}

// } Driver Code Ends