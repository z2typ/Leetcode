class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
        
        int len=0;
        int left = 0;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<=i;j++){
                if(s[i]==s[j]){
                    
                        if(i==j || i-j==1 ||dp[i-1][j+1]){
                            dp[i][j]=true;
                            if(i-j+1 > len){
                                len  = i-j+1;
                                left = j;
                            }
                        }
                }
            }
        }
        
        ans = s.substr(left,len);
        return ans;
    }
};