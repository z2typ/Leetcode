// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
 
     vector<vector<int>> dp;
    int util(string &s,int i, string &t,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 || j==0){
            return dp[i][j] = max(i,j);
        }
        
        if(s[i-1]==t[j-1]){
            return dp[i][j] = util(s,i-1,t,j-1);
        }else{
            return dp[i][j] = min(util(s,i-1,t,j-1),\
                        min(util(s,i,t,j-1),\
                        util(s,i-1,t,j))) + 1;
        }
        
    }
    int editDistance(string s, string t) {
        // Code here

        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp (n+1,vector<int>(m+1,-1));
        this->dp = dp;
        
        return util(s,n,t,m);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends