class Solution {
public:
    vector<int> dp;
    bool breakWord(string s, int n, vector<string>& wordDict){
        if(n==0){
            return true;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        for(string &word : wordDict){
            int wordSize = word.size();
            if(n-wordSize>= 0 && s.substr(n-wordSize)==word){
                if(breakWord(s.substr(0,n-wordSize),n-wordSize,wordDict)){
                    return dp[n]= true;
                }
            }
        }
        
        return dp[n]=false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        dp = vector<int>(n+1,-1);
        return breakWord(s,n,wordDict);
    }
};