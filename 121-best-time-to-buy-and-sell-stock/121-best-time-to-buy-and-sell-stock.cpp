class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_so_far = prices[0];
        int profit = 0;
        
        for(int i=0;i<n;i++){
            min_so_far = min(min_so_far, prices[i]);
            profit = max(profit, prices[i] - min_so_far);
        }
        
        return profit;
        
    }
};