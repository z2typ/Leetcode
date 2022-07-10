class Solution {
public:
    
    bool isMatch(string s, string p) {
        int i = s.size();
        int j = p.size();
        
        vector<vector<int>> t(j+1,vector<int>(i+1,-1));
        
        for(int k=1;k<=i;k++){
            t[0][k] = false;
        }
        
        t[0][0] = true;
        
        bool flag = true;
        for(int l=1;l<=j;l++){
            if(flag && p[l-1]=='*'){
                t[l][0] = true;
            }else{
                flag = false;
                t[l][0] = false;
            }
        }
        
        for(int l=1;l<=j;l++){
            for(int k=1;k<=i;k++){
                if(s[k-1]==p[l-1]){
                    t[l][k] = t[l-1][k-1];
                }else if(p[l-1]=='?'){
                    t[l][k] = t[l-1][k-1];
                }else if(p[l-1]=='*'){
                    t[l][k] = t[l][k-1]||t[l-1][k];
                }else{
                    t[l][k] = false;
                }
            }
        }
        
        
        
        return t[j][i];
        
    }
};