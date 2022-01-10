// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

Node *buildTree(string str)
{
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // Create the root of the tree
  Node *root = new Node(stoi(ip[0]));

  // Push the root to the queue
  queue<Node *> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size())
  {

    // Get and remove the front of the queue
    Node *currNode = queue.front();
    queue.pop();

    // Get the current Node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N")
    {

      // Create the left child for the current Node
      currNode->left = new Node(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N")
    {

      // Create the right child for the current Node
      currNode->right = new Node(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  Node *targetNode;
  map<Node *, Node *> parentMap;
  map<Node *, bool> visitedMap;
  int ans;

  void getParents(Node *root, int target, Node *parent)
  {
    if (!root)
      return;
    if (root->data == target)
      targetNode = root;
    parentMap[root] = parent;
    getParents(root->left, target, root);
    getParents(root->right, target, root);
  }

  int solve(Node *root)
  {
    if (!root || visitedMap[root])
      return 0;
    visitedMap[root] = true;
    int left = solve(root->left);
    int right = solve(root->right);
    int parent = solve(parentMap[root]);
    return max({left, right, parent}) + 1;
  }

  int minTime(Node *root, int target)
  {
    targetNode = NULL;
    parentMap.clear();
    visitedMap.clear();
    ans = INT_MIN;

    getParents(root, target, NULL);
    return solve(targetNode) - 1;
  }
};

// { Driver Code Starts.

int main()
{
  int tc;
  scanf("%d ", &tc);
  while (tc--)
  {
    string treeString;
    getline(cin, treeString);
    // cout<<treeString<<"\n";
    int target;
    cin >> target;
    // cout<<target<<"\n";

    Node *root = buildTree(treeString);
    Solution obj;
    cout << obj.minTime(root, target) << "\n";

    cin.ignore();
  }

  return 0;
}
// } Driver Code Ends