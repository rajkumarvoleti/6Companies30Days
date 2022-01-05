#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  // (n * (n + 1) * ((2 * n) + 1)) / 6
  // to reduce the chances of overflow we use the below formula
  long long ans = (n * (n + 1) / 2) * ((2 * n) + 1) / 6;
  cout << ans << endl;
}