// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool isCycle(vector<vector<int>> &graph,int src,bool seen[],bool root[]){
        seen[src] = true;
        root[src] = true;
        for(auto &ele: graph[src]){
            if(root[ele]) return true;
            if(!seen[ele] && isCycle(graph,ele,seen,root)) return true;
        }
        root[src] = false;
        return false;
    }

	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<vector<int>> graph(N);
	    for(int i = 0; i < pre.size(); i++){
	        graph[pre[i].first].push_back(pre[i].second);
	    }
	    
	    bool seen[N] = {0}, root[N] = {0};
	 
	    for(int i = 0; i < N; i++){
	        if(!seen[i] && isCycle(graph,i,seen,root)) return false;
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends