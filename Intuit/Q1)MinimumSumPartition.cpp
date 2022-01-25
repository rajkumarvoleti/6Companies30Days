// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
  
    int ans;
  
    void solve(int arr[],int n,int pos,int totalSum,int sum, vector<vector<bool>> &visited){
        if(visited[pos][sum]) return;
        visited[pos][sum] = true;
        
        ans = min(ans,abs(totalSum-(2*sum)));
        if(2*sum >= totalSum) return;
        if(pos + 1 >= n) return;
        solve(arr,n,pos+1,totalSum,sum+arr[pos+1],visited);
        solve(arr,n,pos+1,totalSum,sum,visited);
    }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    ans = INT_MAX;
	    for(int i = 0; i < n; i++) sum += arr[i];
	    vector<vector<bool>> visited(n,vector<bool>(sum+1,false));
	    // sum1 + sum2 = sum => sum1 = sum - sum2 => sum1 - sum2 = sum = (2*sum2)
	    // min of  abs(totalSum - (2*subsetSum) )
	    solve(arr,n,0,sum,0,visited);
	    solve(arr,n,0,sum,arr[0],visited);
	    return ans;
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

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends