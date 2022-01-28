#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getSteps(string str, char c)
  {
    int size = str.length();
    int i = 0, steps = 0;

    while (i < size)
    {
      int count = 0;
      while (str[i] == c)
      {
        count++;
        i++;
      }
      if (count > 2)
        steps += count - 2;
      i++;
    }
    return steps;
  }

  bool winnerOfGame(string colors)
  {
    int steps1 = getSteps(colors, 'A');
    int steps2 = getSteps(colors, 'B');
    return steps1 > steps2;
  }
};