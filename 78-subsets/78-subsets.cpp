class Solution {
public:
    void util(vector<int>& nums, int n,vector<int> &vac, vector<vector<int>> &ans){
        
        if(n==0){
            ans.push_back(vac);
            return;
        }
        
        vac.push_back(nums[n-1]);
        util(nums, n-1, vac, ans);
        vac.pop_back();
        
        util(nums,n-1,vac,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> vac;
        vector<vector<int>> ans;
        
        util(nums, n, vac, ans);
        
        return ans;
    }
};