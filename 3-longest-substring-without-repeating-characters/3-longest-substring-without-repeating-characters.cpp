class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        unordered_set<char> uset;
        int res = 0;
        for(int j = 0; j<n; j++){
            if(uset.count(s[j])==0){
                uset.insert(s[j]);
            }else{
                while(uset.count(s[j])){
                    uset.erase(s[i]);
                    i++;
                }
                uset.insert(s[j]);
            }
            
            res = max(res,(j-i+1));
        }
        return res;
    }
};