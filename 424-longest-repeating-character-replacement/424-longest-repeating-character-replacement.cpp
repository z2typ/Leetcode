class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0;
        int n = s.size();
        unordered_map<char,int> umap;
        int max_ct = 0;
        int max_length = 0;
        for(r=0;r<n;r++){
            umap[s[r]]++;
            
            max_ct = max(max_ct,umap[s[r]]);
            
            while(r-l+1-max_ct > k){
                umap[s[l]]--;
                l++;
            }
            max_length = max(max_length,r-l+1);
        }
        
        return max_length;
    }
};