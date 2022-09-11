class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> umap;
        
        for(int i = 0; i < n; i++){
            umap[nums[i]] += 1;
        }
        
        vector<vector<int>> count(n+1);
        
        for(auto it : umap){
            count[it.second].push_back(it.first);
        }
        vector<int> res;
        for(int i=n;i>=0;i--){
            for(int x : count[i]){
                res.push_back(x);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }
};