class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int current_sum = 0;
        for(int x: nums){
            current_sum += x;
            if(current_sum>max_sum){
                max_sum = current_sum;
            }
            
            if(current_sum<0) current_sum=0;
        }
        
        return max_sum;
    }
};