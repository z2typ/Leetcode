class Solution {
public:
    int bs(vector<int>&nums,int target, bool first_occurance){
        int l=0,r = nums.size()-1;
        int ans = -1;
        while(l<=r){
            int mid = (l+r)/2;
            
            if(nums[mid]==target){
                if(first_occurance)
                    r = mid-1;
                else
                    l = mid+1;
                ans = mid;
            }else if(nums[mid]<target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        
        return {bs(nums,target,true),bs(nums,target,false)};
    }
};