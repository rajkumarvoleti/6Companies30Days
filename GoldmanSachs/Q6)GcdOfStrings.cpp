#include <iostream>
using namespace std;

class Solution
{
public:
  bool divides(string quotient, string divider)
  {
    int qsize = quotient.length();
    int dsize = divider.length();
    if (qsize % dsize != 0)
      return false;
    int i = 0;
    while (i < qsize)
    {
      if (quotient.substr(i, dsize) != divider)
        return false;
      i += dsize;
    }
    return true;
  }

  string gcdOfStrings(string str1, string str2)
  {
    string ans = "";
    string divider = "";
    int size1 = str1.length();
    int size2 = str2.length();
    for (int i = 0; i < size1; i++)
    {
      divider.push_back(str1[i]);
      if (divides(str1, divider) && divides(str2, divider))
        ans = divider;
    }
    return ans;
  }
};