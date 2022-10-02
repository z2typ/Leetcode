class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> smap;
        unordered_set<char> uset;
        
        for(int i=0; i<s.length(); i++){
            if(smap.count(s[i]) && smap[s[i]]!=t[i]){
                return false;
            }
            smap[s[i]] = t[i];
        }
        
        for(auto it : smap){
            uset.insert(it.second);
        }
        
        if(uset.size() != smap.size()){
            return false;
        }
        return true;
    }
};