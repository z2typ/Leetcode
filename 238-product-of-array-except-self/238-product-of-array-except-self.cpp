class Solution {
public:
    int value(vector<int> & arr,int idx){
        int n = arr.size();
        if(0<=idx && idx<n){
            return arr[idx];
        }
        return 1;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> sufix(n);
        prefix[0] = nums[0];
        sufix[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]*nums[i];
        }
        
        for(int i=n-2;i>=0;i--){
            sufix[i] = sufix[i+1]*nums[i];
        }
        
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            ans[i] = value(prefix,i-1)*value(sufix,i+1);
        }
        
        return ans;
        
    }
};