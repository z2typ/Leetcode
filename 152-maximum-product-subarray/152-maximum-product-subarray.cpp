class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        vector<int> vec(n);
        arr[0]= vec[0] = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==0){
                arr[i] = 1;
                vec[i] = 1;
                ans = max(ans,0);
            }else{
                arr[i] = max({nums[i],nums[i]*arr[i-1],nums[i]*vec[i-1]});
                vec[i] = min({nums[i],nums[i]*arr[i-1],nums[i]*vec[i-1]});
                ans = max(ans,arr[i]);
            }
        }
        
        return ans;
    }
};