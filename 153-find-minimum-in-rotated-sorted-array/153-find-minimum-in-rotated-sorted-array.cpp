class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = nums.size()-1;
        
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]>=nums[0]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return nums[l%n];
    }
};