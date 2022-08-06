class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans1, ans2;
        int cnt1 = 0, cnt2 = 0;
        
        for(int i=0;i<n;i++){
            if(ans1==nums[i]){
                cnt1++;
            }else if(ans2==nums[i]){
                cnt2++;
            }else if(cnt1==0){
                ans1 = nums[i];
                cnt1 = 1;
            }else if(cnt2==0){
                ans2 = nums[i];
                cnt2 = 1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int i=0;i<n;i++){
            if(ans1==nums[i]){
                cnt1++;
            }else if(ans2==nums[i]){
                cnt2++;
            }
        }
        vector<int> a;
        if(cnt1>(n/3)){
            a.push_back(ans1);
        }
        if(cnt2>(n/3)){
            a.push_back(ans2);
        }
        return a;
        
    }
};