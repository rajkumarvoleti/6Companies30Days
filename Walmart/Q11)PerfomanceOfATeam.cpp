#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  typedef long long ll;
  ll mod = 1e9 + 7;

  static bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
  {
    return a.first > b.first;
  }

  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
  {

    vector<pair<ll, ll>> pairs;
    n = speed.size();
    for (int i = 0; i < n; i++)
      pairs.push_back({efficiency[i], speed[i]});
    sort(pairs.begin(), pairs.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> pq;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      pq.push(pairs[i].second);
      sum += pairs[i].second;
      if (pq.size() > k)
      {
        int top = pq.top();
        pq.pop();
        sum -= top;
      }
      ans = max(ans, sum * pairs[i].first);
    }
    return ans % mod;
  }
};