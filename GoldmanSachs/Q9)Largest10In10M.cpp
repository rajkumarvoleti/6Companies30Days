#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main()
{
  int size;
  cin >> size;
  int arr[size];
  for (int i = 0; i < size; i++)
    cin >> arr[i];

  set<int> Set;
  for (int i = 0; i < size; i++)
  {
    if (Set.size() < 10)
      Set.insert(arr[i]);
    else if (*Set.begin() < arr[i])
    {
      Set.erase(Set.begin());
      Set.insert(arr[i]);
    }
  }
  while (!Set.empty())
  {
    cout << *Set.begin() << " ";
    Set.erase(Set.begin());
  }
  cout << endl;
}