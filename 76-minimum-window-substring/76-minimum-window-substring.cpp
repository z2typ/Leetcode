class Solution {
public:
    bool valid(unordered_map<char,int> &a,unordered_map<char,int> &b){
        for(auto it=b.begin();it!=b.end();it++){
            if(a[it->first] < it->second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        int l = -1;
        
        unordered_map<char,int> umap_s, umap_t;
        
        for(char ch : t){
            umap_t[ch]++;
        }
        int Left = 0;
        int Right = -1;
        int windowSize = INT_MAX;
        for(int r=0;r<n;r++){
            umap_s[s[r]]++;
            
            if(!valid(umap_s, umap_t)){
                continue;
            }
            
            while(valid(umap_s,umap_t)){
                l++;
                umap_s[s[l]]--;
            }
            if(windowSize >(r-l+1)){
                windowSize = (r-l+1);
                Left = l;
                Right = r;
            }
            
        }
        
        return s.substr(Left,Right-Left+1);

    }
};