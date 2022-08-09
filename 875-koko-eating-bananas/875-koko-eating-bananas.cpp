class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        
        while(l<=r){
            long long k = (l+r)/2;
            long long count = 0;
            for(int pile : piles){
                count += ceil(pile/(k*1.0));
            }
            
            if(count>h){
                l = k+1;
            }else{
                r = k-1;
            }
        }
        return l;
        
    }
};