class Solution {
public:
    vector<vector<int>> dp;
    bool Interleaving(string &s1,int n1, string &s2, int n2, string &s3, int n3){
        if(n1==0 && n2==0 && n3==0){
            return true;
        }
        if(n1>0 && n2>0 && n3>0 && dp[n1][n2]!=-1){
            return dp[n1][n2];
        }
        if(n1>0 && n2>0 && n3>0 && s3[n3-1] == s1[n1-1] && s3[n3-1] == s2[n2-1]){
            return dp[n1][n2] = Interleaving(s1,n1-1,s2,n2,s3,n3-1) || Interleaving(s1,n1,s2,n2-1,s3,n3-1);
        }else if(n1>0 && n3>0 && s3[n3-1] == s1[n1-1]){
            return dp[n1][n2] = Interleaving(s1,n1-1,s2,n2,s3,n3-1);
        }else if(n2>0 && n3>0 && s3[n3-1] == s2[n2-1]){
            return dp[n1][n2] = Interleaving(s1,n1,s2,n2-1,s3,n3-1);
        }else{
            return dp[n1][n2] = false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(),n2 = s2.size(), n3 = s3.size();
        if(n3!=n1+n2){
            return false;
        }
        dp = vector<vector<int>>(n1+1,vector<int>(n2+1,-1));
        return Interleaving(s1,n1,s2,n2,s3,n3);
    }
};