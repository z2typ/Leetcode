// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:

    long long int count(int coins[], int n, int m) {
        long long amount = m;
        vector<vector<long long>> t(n+1,vector<long long>(amount+1));

        // initialiazing the array
        for(int i=0;i<=n;i++){
            t[i][0]=1;
        }

        // applying tabulation approach
        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(S[i-1]>amount){
                    return t[i][j] = t[i-1][j];
                }else{
                    return t[i][j] = t[i][j-S[i-1]] + t[n-1][j];
                }
            }
        }

        return t[n][amount];
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
