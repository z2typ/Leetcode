class Solution {
public:
    int util(vector<int>&nums , int n,vector<int>&t){
        if(t[n] != -1) return t[n];
        if(n==0) return t[n] = 0;
        else if(n==1) return t[n] = nums[0];
        return t[n] = max(util(nums,n-2,t)+nums[n-1],util(nums,n-1,t));
    }
    int rob(vector<int>& nums) {
        vector<int> t(nums.size()+1,-1);
        return util(nums,nums.size(),t);
    }
};