class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int l = 0;
        long long Total = 0;
        int maxWindowLength = 0;
        for(int r = 0; r < n; r++){
            Total += nums[r];
            
            if((long long)nums[r]*(r-l+1) <= (long long)Total+k){
                maxWindowLength = max(r-l+1, maxWindowLength);
            }else{
                while((long long)nums[r]*(r-l+1) > (long long)Total+k){
                    Total -= nums[l];
                    l += 1;
                }
            }
            
        }
            
        return maxWindowLength;
    }
};