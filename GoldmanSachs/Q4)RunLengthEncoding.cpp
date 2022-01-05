// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);

int main()
{

  int T;
  cin >> T;
  while (T--)
  {
    string str;
    cin >> str;

    cout << encode(str) << endl;
  }
  return 0;
} // } Driver Code Ends

/*You are required to complete this function */

string encode(string src)
{
  // Your code here
  string s = "";
  int size = src.length(), i = 0, count = 1;
  while (i < size)
  {
    s.push_back(src[i]);
    i++;
    int top = s.length() - 1;
    while (s[top] == src[i] && i < size)
    {
      count++;
      i++;
    }
    s += to_string(count);
    count = 1;
  }
  return s;
}
