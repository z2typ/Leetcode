// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int value_at(vector<vector<int>> &M,int x,int y){
        int n = M.size();
        int m = M[0].size();
        if(0<=x && x<n && 0<=y && y<m){
            return M.at(x).at(y);
        }
            return 0;
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        for(int j=m-2;j>=0;j--){
            for(int i=0;i<n;i++){
                M[i][j] += max(value_at(M,i,j+1),max( value_at(M,i+1,j+1),value_at(M,i-1,j+1) ) );
            }
        }
        
        int max_val = INT_MIN;
        for(int i=0;i<n;i++){
            if(max_val<M.at(i).at(0)){
                max_val = M.at(i).at(0);
            }
        }
        
        return max_val;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends