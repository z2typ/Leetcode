class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> p(n);
        p[n-1] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            p[i] = max(p[i+1],prices[i]);
        }
        int max_profit = INT_MIN;
        for(int i=0;i<n;i++){
            max_profit = max(max_profit,p[i]-prices[i]);
        }
        // if(max_profit<0) return 0;
        return max_profit;
        
    }
};