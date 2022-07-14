// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
        
        vector<int> dp(N,0);
        
        for(int i=N-1;i>=0;i--){
            for(int j=i+1;j<=N-1;j++){
                if(A[i]+1==A[j] || A[i]-1==A[j]){
                    dp[i] = max(dp[i],dp[j]);
                }
            }
            dp[i]++;
        }

        
        return *max_element(dp.begin(),dp.end());
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends