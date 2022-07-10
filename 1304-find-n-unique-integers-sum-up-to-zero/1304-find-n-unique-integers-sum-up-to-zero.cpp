class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        
        for(int i=0;i<n-1;i++){
            ans[i] = i+1;
        }
        
        ans[n-1] = -((n)*(n-1))/2;
        return ans;
        
    }
};