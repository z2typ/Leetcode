class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> strs_cpy = strs; // O(n)
        
        for(string & s : strs_cpy){ // O(n*log(m))
            sort(s.begin(),s.end());
        }
        
        unordered_map<string,vector<string> > umap;
        
        for(int i=0;i<n;i++){
            umap[strs_cpy[i]].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for( auto it : umap){
            res.push_back(it.second);
        }
        
        return res;
        
    }
};