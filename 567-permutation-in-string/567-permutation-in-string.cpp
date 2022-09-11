class Solution {
public:
    template<class T>
    void erase(unordered_map<T,int> &umap,T ch){
        if(umap[ch]==1){
            umap.erase(ch);
        }else{
            umap[ch]--;
        }
    }
    
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1>n2){
            return false;
        }
        int l = 0;
        unordered_map<char,int> umap1;
        
        for(char ch : s1){
            umap1[ch] += 1;
        }
        
        unordered_map<char,int> umap2;
        for(int r = 0; r < n1; r++){
            umap2[s2[r]]++;
        }
        
        if(umap2 == umap1){
            return true;
        }
        
        int r = n1;
        while(r < n2){
            umap2[s2[r]]++;
            erase(umap2,s2[l]);
            r++;
            l++;
            if(umap2 == umap1){
                return true;
            }
        }
        return false;
    }
};