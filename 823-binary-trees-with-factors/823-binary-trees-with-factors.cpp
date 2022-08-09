const int MOD = 1e9 + 7;
class Solution {
public:
    
    int mul(long int a, long int b){
        return ((a)%MOD*(b)%MOD)%MOD;
    }
    
    int add(long int a, long int b){
        return ((a)%MOD+(b)%MOD)%MOD;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<int> dp(n,1);
        
        unordered_map<int, int> idx;
        for(int i = 0;i<n;i++){
            idx[arr[i]] = i;
        }
        
        for(int j=1;j<n;j++){
            
            for(int k=0;k<j;k++){
                if(arr[j]%arr[k]==0){
                    if(idx.count(arr[j]/arr[k])){
                        dp[j] = add(dp[j], mul(dp[k],dp[idx[arr[j]/arr[k]]]));
                    }
                }
            }
            
        }
        
        int noOfBinaryTrees = 0;
        
        for(int x:dp){
            noOfBinaryTrees  = add(noOfBinaryTrees,x);
        }
        return noOfBinaryTrees;
        
    }
};