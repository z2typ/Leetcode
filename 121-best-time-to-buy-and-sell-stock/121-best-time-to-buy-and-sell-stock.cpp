class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_sofar = INT_MAX;
        int maxProfit = 0;
        for(int x : prices){
            min_sofar = min(min_sofar, x);
            maxProfit = max(maxProfit, x-min_sofar);
        }
        return maxProfit;
    }
};