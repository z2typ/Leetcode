class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int max_jump = nums[0];
        int jumps = 0;
        while(j<n-1){

            for(int k=i;k<=min(j,n-1);k++){
                if(nums[k]+k>max_jump){
                    max_jump = nums[k]+k;
                }
            }
                        i = j+1;
            j = max_jump;
            jumps++;
        }
        return jumps;
    }
};