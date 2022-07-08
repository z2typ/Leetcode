class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        if(n==1) return nums[0];
        else if(n==0) return 0;
        
        int a = nums[0];
        int b = max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            int temp = max(a+nums[i], b);
            a = b;
            b = temp;
        }
        
        return max(a,b);
    }
};