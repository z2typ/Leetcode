class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        if(n==0) return 0;
        
        vector<vector<bool>> dp(n,vector<bool>(n));
        int len = 0;
        int left_idx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(s[i]==s[j]){
                    if(i==j||i-j==1||dp[i-1][j+1]){
                        dp[i][j] =true;
                        if(i-j+1 > len){
                            left_idx = j;
                            len = (i-j+1);
                        }
                        
                    }
                }
            }
        }
        

        
        return s.substr(left_idx,len);
    }
};