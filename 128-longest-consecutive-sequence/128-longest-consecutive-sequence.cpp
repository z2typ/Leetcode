class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        int maxLength = 0;
        int j;
        if(nums.empty()){
            return 0;
        }
        for(j=1;j<n;j++){
            if(nums[j]-1==nums[j-1]){
                
            }else if(nums[j]==nums[j-1]){
                i++;
            }else{
                maxLength = max(maxLength,j-i);
                i = j;
            }
            
        }
        
        maxLength = max(maxLength,j-i);
        
        return maxLength;

    }
};