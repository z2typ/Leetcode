class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s_map;
        for(char ch : s){
            s_map[ch]++;
        }
        unordered_map<char,int> t_map;
        for(char ch:t){
            t_map[ch]++;
        }
        
        return s_map==t_map;
    }
};