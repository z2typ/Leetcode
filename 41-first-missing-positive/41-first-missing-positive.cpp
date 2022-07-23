class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] <= 0){
                nums[i] = n+2;
            }
        }
        
        for(int i=0;i<n;i++){
            if(abs(nums[i])-1>=0 && abs(nums[i])-1<n)
                nums[abs(nums[i])-1]  = -abs(nums[abs(nums[i])-1]);
        }
        
        int fMissing=0;

        while(fMissing<n && nums[fMissing]<0){
            fMissing++;
        }
        
        return fMissing+1;
        
    }
};