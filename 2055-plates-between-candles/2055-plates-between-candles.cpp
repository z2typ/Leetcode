class Solution {
public:
pair<int,int> bs(vector<int>&arr,int target){
    int l = 0;
    int r = arr.size()-1;

    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==target){
            return {mid,mid};
        }else if(arr[mid]<target){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return {r,l};
}
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int len = s.size();
        
        vector<int> candles;
        
        for(int i=0;i<len;i++){
            if(s[i]=='|'){
                candles.push_back(i);
            }
        }
        
        int len_candles = candles.size();
        
        vector<int> ans;
        
        for(vector<int> q : queries){
            int candle_a = bs(candles,q[0]).second;
            int candle_b = bs(candles,q[1]).first;
            int betweenCandles = (candle_b-candle_a)-1;
            if(betweenCandles>=0)
            ans.push_back((candles[candle_b]-candles[candle_a]-1)-betweenCandles);
            else ans.push_back(0);
        }
        
        return ans;
    }
};