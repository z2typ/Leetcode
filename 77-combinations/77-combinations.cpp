class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int s,int n,int k,vector<int> & ans){
        if(ans.size()==k){
            res.push_back(ans);
            return;
        }
        for(int i=s;i<=n;i++){
            ans.push_back(i);
            backtrack(i+1,n,k,ans);
            ans.pop_back();
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        backtrack(1,n,k,ans);
        return res;
    }
};