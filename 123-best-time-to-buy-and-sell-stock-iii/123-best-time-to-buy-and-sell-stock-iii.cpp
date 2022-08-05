class Solution {
public:
    vector<vector<vector<int>>> t;
    int util(vector<int>& arr,int i, int buy, int count){
        if(i==arr.size() || (buy==1 && count==0)){
            return 0;
        }
        
        if(t[i][buy][count]!=-1){
            return t[i][buy][count];
        }
        
        if(buy){
                    // Sell Stocks
            return t[i][buy][count] = max(util(arr,i+1,0,count-1) - arr[i],
                       
                       // Dont do anything
                       util(arr,i+1,1,count));
            
        }else{      // 
            return t[i][buy][count] = max(util(arr,i+1,1,count) + arr[i],
                       //  
                       util(arr,i+1,0,count));
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        t = vector<vector<vector<int>>>(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return util(prices,0,1,2);
    }
};