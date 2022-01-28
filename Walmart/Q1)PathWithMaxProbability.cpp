#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  typedef pair<int, double> pid;
  typedef pair<double, int> pdi;

  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
  {

    vector<vector<pid>> graph(n);
    for (int i = 0; i < edges.size(); i++)
    {
      int src = edges[i][0];
      int dst = edges[i][1];
      double prob = succProb[i];
      graph[src].push_back({dst, prob});
      graph[dst].push_back({src, prob});
    }
    vector<double> probability(n, (double)0.0);
    probability[start] = 1.0;

    priority_queue<pdi> pq;
    pq.push({1.0, start});
    while (!pq.empty())
    {
      int src = pq.top().second;
      pq.pop();
      for (auto &ele : graph[src])
      {
        int pos = ele.first;
        double currProb = ele.second;
        if (probability[pos] < probability[src] * currProb)
        {
          probability[pos] = probability[src] * currProb;
          pq.push({probability[pos], pos});
        }
      }
    }
    return probability[end];
  }
};