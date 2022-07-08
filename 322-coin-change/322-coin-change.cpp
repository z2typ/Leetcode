class Solution {
public:
    int util(vector<int>& coins, int n, int amount,vector<vector<int>> &t){
        if(t[n][amount] != -1) return t[n][amount];
        if(amount==0){
            return t[n][amount] = 0;
        }else if(n==0){
            return t[n][amount] = 100000000;
        }
        
        if(coins[n-1]>amount){
            return t[n][amount] = util(coins,n-1,amount,t);
        }else{
            return t[n][amount] = min(util(coins,n,amount-coins[n-1],t)+1,util(coins,n-1,amount,t));
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> t(n+1,vector<int>(amount+1,-1));
        int ans = util(coins,n,amount,t);
        if(ans>=100000000) return -1;
        return ans;
    }
};