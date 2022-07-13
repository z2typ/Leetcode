class Solution {
public:
      vector<vector<int>> dp;
    int util(string &s,int i, string &t,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 || j==0){
            return dp[i][j] = max(i,j);
        }
        
        if(s[i-1]==t[j-1]){
            return dp[i][j] = util(s,i-1,t,j-1);
        }else{
            return dp[i][j] = min(util(s,i-1,t,j-1),\
                        min(util(s,i,t,j-1),\
                        util(s,i-1,t,j))) + 1;
        }
        
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        this->dp = vector(n+1,vector<int>(m+1,-1));
        
        return util(word1,n,word2,m);
    }
};