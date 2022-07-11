class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();

        
        string rev(s);
        reverse(rev.begin(), rev.end());
        string s_new = s + "#" + rev;
        int n_new = s_new.size();
        
        int LPS[n_new];
        LPS[0] = 0;
        int prevLPS = 0, i = 1;
        
        while(i<n_new){
            if(s_new[prevLPS]==s_new[i]){
                LPS[i] = prevLPS+1;
                i++;
                prevLPS++;
            }else if(prevLPS==0){
                LPS[i] = 0;
                i++;
            }else{
                prevLPS = LPS[prevLPS-1];
            }
        }
        
        
        return rev.substr(0, n - LPS[n_new - 1]) + s;
        
    }
};