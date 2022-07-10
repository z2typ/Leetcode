class Solution {
public:
    bool util(string s, int i, string p, int j,vector<vector<int>> &t){
        
        if(t[i][j]!=-1) return t[i][j];
        
        if(i==0 && j==0){
            return t[i][j] = true;
        }else if(j==0 && i>0){
            return t[i][j] = false;
        }else if(i==0 && j>0){
            if(p[j-1]=='*') return t[i][j] = util(s,i,p,j-2,t);
            else return t[i][j] = false;
        }
        
        if(s[i-1]==p[j-1]){
            return t[i][j] = util(s,i-1,p,j-1,t);
        }else if(p[j-1]=='.'){
            return t[i][j] = util(s,i-1,p,j-1,t);
        }else if(p[j-1]=='*'){
            int ch = p[j-2];
            bool a1 = false;
            bool a2 = false;
            
            a1 = util(s,i,p,j-2,t);
            
            if(ch=='.' || s[i-1]==ch)
                a2 = util(s,i-1,p,j,t);
            
            return t[i][j] = a1||a2;
            
        }else{
            return t[i][j] = false;
        }
    }
    
    bool isMatch(string s, string p) {
        int i = s.size();
        int j = p.size();
        
        vector<vector<int>> t(i+1,vector<int>(j+1,-1));
        
        return util(s,i,p,j,t);
        
    }
};