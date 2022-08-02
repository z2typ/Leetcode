class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minimum = prices[0];
        int profit = 0;
        for(int i=0; i<n; i++){
            if(prices[i]<minimum){
                minimum = prices[i];
            }
            if(prices[i]-minimum > profit){
                profit = prices[i]-minimum;
            }
            
        }
        return profit;
    }
};