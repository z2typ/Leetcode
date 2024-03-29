class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        set<vector<int>> st;
        for(int i=0; i<n; i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int l = i+1, r = n-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    st.insert({nums[i], nums[l], nums[r]});
                    // while(l<r && nums[l] == nums[l+1])
                    //     l++;
                    // while(l<r && nums[r-1] == nums[r])
                    //     r--;
                    l++;
                }else if(sum < 0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        for(auto it : st){
            res.push_back(it);
        }
        return res;
    }
};