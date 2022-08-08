class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
        map<map<char,int>, vector<string>> mp;
        
        for(int i=0;i<strs.size();i++){
            map<char,int> umap;
            for(char ch:strs[i]){
                umap[ch]++;
            }
            mp[umap].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
        
        
    }
};