class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        
        int maxLength = 1;
        int start_idx = 0;
        for(int i=0;i<n;i++){
            for(int j=0; j<i; j++){
                if(s[i]==s[j] && (dp[j+1][i-1]==true || i-j==1 || i-1==j+1)){
                    dp[j][i] = true;
                    if(i-j+1 > maxLength){
                        start_idx = j;
                        maxLength = i-j+1;
                    }
                }
            }
        }
        return s.substr(start_idx,maxLength);
    }
};