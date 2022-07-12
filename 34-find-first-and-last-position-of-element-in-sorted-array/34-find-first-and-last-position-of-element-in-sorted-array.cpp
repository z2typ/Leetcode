class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r = nums.size()-1;
        int facc = -1;
        while(l<=r){
            int mid = (l+r)/2;
            
            if(nums[mid]==target){
                if( mid-1>=0 && nums[mid-1]==nums[mid]){
                    r = mid-1;
                }else{
                    facc = mid;
                    break;
                }
            }else if(nums[mid]<target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        l=0,r = nums.size()-1;
        int lacc = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                if( mid+1<nums.size() && nums[mid]==nums[mid+1]){
                    l = mid+1;
                }else{
                    lacc = mid;
                    break;
                }
            }else if(nums[mid]<target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        
        return {facc,lacc};
    }
};