// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  struct Trie
  {
    struct Trie *children[26];
    bool isEnd = false;
  };

  Trie *getNode()
  {
    Trie *root = new Trie;
    for (int i = 0; i < 26; i++)
    {
      root->children[i] = NULL;
    }
    return root;
  }

  void insertString(Trie *root, string s)
  {
    Trie *it = root;
    for (int i = 0; i < s.length(); i++)
    {
      int pos = s[i] - 'a';
      if (!it->children[pos])
        it->children[pos] = getNode();
      it = it->children[pos];
    }
    it->isEnd = true;
  }

  void searchUtil(Trie *root, vector<string> &ans, string word)
  {
    if (root->isEnd)
      ans.push_back(word);
    for (int i = 0; i < 26; i++)
    {
      if (!root->children[i])
        continue;
      searchUtil(root->children[i], ans, word + (char)('a' + i));
    }
  }

  vector<vector<string>> search(Trie *root, string str)
  {
    Trie *it = root;
    string prefix;
    vector<vector<string>> ans;
    for (int i = 0; i < str.length(); i++)
    {
      int pos = str[i] - 'a';
      prefix += str[i];
      if (!it->children[pos])
        break;
      it = it->children[pos];
      vector<string> temp;
      searchUtil(it, temp, prefix);
      ans.push_back(temp);
    }
    vector<string> zero = {"0"};
    while (ans.size() < str.length())
      ans.push_back(zero);
    return ans;
  }

  vector<vector<string>> displayContacts(int n, string contact[], string reqStr)
  {
    // code here
    Trie *root = getNode();
    for (int i = 0; i < n; i++)
    {
      insertString(root, contact[i]);
    }
    return search(root, reqStr);
  }
};

// { Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string contact[n], s;
    for (int i = 0; i < n; i++)
      cin >> contact[i];
    cin >> s;

    Solution ob;
    vector<vector<string>> ans = ob.displayContacts(n, contact, s);
    for (int i = 0; i < s.size(); i++)
    {
      for (auto u : ans[i])
        cout << u << " ";
      cout << "\n";
    }
  }
  return 0;
} // } Driver Code Ends