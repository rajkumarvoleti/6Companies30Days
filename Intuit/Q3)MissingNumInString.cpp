// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/

int stringToInt(string &s){
    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        ans = (ans*10) + (s[i]-'0');
    }
    return ans;
}

int missingNumber(const string& str)
{
    // Code here
    int n = str.length();
    int ans = -1;
    for(int len = 1; len < n; len++){
        string temp = "";
        int i = 0, l = len;
        bool flag = 0;
        
        while(i < n && l--){
            temp += str[i];
            i++;
        } 
        int prev = stringToInt(temp);
        temp = "";
        
        int count = 0;
        while(i < n && !flag){
            temp += str[i];
            i++;
            int num = stringToInt(temp);
            if(prev + 1 == num){
                prev = num;
                temp = "";
            }
            else if(prev + 2 == num){
                ans = prev + 1;
                prev = num;
                count++;
                temp = "";
            }
            else if(prev < num) flag = 1;
        }
        
        if(count == 1 && flag == 0 && temp == "")
            return ans;
        
    }
    return -1;
}