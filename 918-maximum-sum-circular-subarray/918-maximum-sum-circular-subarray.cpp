class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currSumMax = 0, maxSum = nums[0], currSumMin = 0, minSum = nums[0];
        int sum = 0;
        
        for(int x : nums){
            
            sum += x;
            
            maxSum = max(maxSum,currSumMax + x);
            currSumMax = max(currSumMax + x,0);
            
            minSum = min(minSum,currSumMin + x);
            currSumMin = min(currSumMin + x,0);
            
        }
        
        if(sum == minSum){ 
            return maxSum;
        }
        
        return max(maxSum, sum - minSum);
    }
};