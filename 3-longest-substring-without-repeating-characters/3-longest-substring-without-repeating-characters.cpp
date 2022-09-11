class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0;
        int maxLength = 0;
        unordered_set<char> st;
        for(int r = 0; r < n; r++){
            if(!st.count(s[r])){
                st.insert(s[r]);
                maxLength = max(maxLength, r - l + 1);
            }else{
                while(st.count(s[r])){
                    st.erase(s[l]);
                    l += 1;
                }
                st.insert(s[r]);
            }
        }
        return maxLength;
    }
};