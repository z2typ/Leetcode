// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
      long long util(int coins[], long long n, long long amount,vector<vector<long long>> &t){
        if(t[n][amount] != -1) return t[n][amount];
        if(amount==0){
            return t[n][amount] = 1;
        }else if(n==0){
            return t[n][amount] = 0;
        }
        
        if(coins[n-1]>amount){
            return t[n][amount] = util(coins,n-1,amount,t);
        }else{
            return t[n][amount] = util(coins,n,amount-coins[n-1],t)+util(coins,n-1,amount,t);
        }
    }
    long long int count(int S[], int n, int m) {
        long long amount = m;
        vector<vector<long long>> t(n+1,vector<long long>(amount+1,-1));
        long long ans = util(S,n,amount,t);
        // if(ans>=100000000) return -1;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends