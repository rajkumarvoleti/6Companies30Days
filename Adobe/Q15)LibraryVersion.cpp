#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getNumber(string &str, int &i)
  {
    int size = str.length();
    string ans = "";
    while (i < size && str[i] != '.')
    {
      ans.push_back(str[i]);
      i++;
    }
    if (i < size && str[i] == '.')
      i++;
    return stoi(ans);
  }

  int compareVersion(string &version1, string &version2)
  {
    int i = 0, j = 0;
    int size1 = version1.length(), size2 = version2.length();
    while (i < size1 || j < size2)
    {
      int num1 = i < size1 ? getNumber(version1, i) : 0;
      int num2 = j < size2 ? getNumber(version2, j) : 0;
      if (num1 == num2)
        continue;
      else if (num1 > num2)
        return 1;
      else
        return -1;
    }
    return 0;
  }
};

int main()
{
  return 0;
}
