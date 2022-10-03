class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currSumMax = 0;
        int maxSum = nums[0];
        
        int minSum = nums[0];
        int currSumMin = 0;
        
        int sum = 0;
        for(int r=0; r<n; r++){
            
            sum += nums[r];
            
            currSumMax += nums[r];
            maxSum = max(maxSum,currSumMax);
            if(currSumMax < 0){
                currSumMax = 0;
            }
            
            currSumMin += nums[r];
            minSum = min(minSum,currSumMin);
            if(currSumMin > 0){
                currSumMin = 0;
            }
            
        }
        if(sum == minSum){ 
            return maxSum;
        }
        return max(maxSum, sum - minSum);
    }
};