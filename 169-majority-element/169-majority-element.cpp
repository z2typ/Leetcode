class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int x = nums[0];
        int ct = 0;
        
        for(int i=0;i<nums.size();i++){
            if(x==nums[i]){
                ct += 1;
            }else{
                ct--;
                if(ct==0){
                    ct=1;
                    x = nums[i];
                }
            }
        }

        return x;
    }
};