class Solution {
public:
    int util(vector<int>& nums, int left,int right) {
        int n = right-left+1;
        vector<int> ans(n);
        if(n==1) return nums[left];
        else if(n==0) return 0;
        
        int a = nums[left];
        int b = max(nums[left],nums[left+1]);
        
        for(int i=2;i<n;i++){
            int temp = max(a+nums[left+i], b);
            a = b;
            b = temp;
        }
        return max(a,b);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        else if(n==1) return nums[0];
        return max(util(nums,0,n-2),util(nums,1,n-1));
    }
};