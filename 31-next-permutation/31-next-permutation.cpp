class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        // int j = n-1;
        while(0<=i && nums[i]>=nums[i+1]){
            i--;
        }
        if(i==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int j=n-1;j>i;j--){
            if(nums[j]>nums[i]){
                swap(nums[i],nums[j]);
                break;
            }
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
