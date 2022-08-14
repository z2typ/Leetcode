class Solution {
public:
    vector<string> ans;
    void paren(int n, int open,int closed,string s=""){
        if(closed==n){
            ans.push_back(s);
            return;
        }
        
        if(open==closed && open < n){
            paren(n,open+1,closed,s+"(");
        }else if(open>closed){
            if(open<n){
                paren(n,open+1,closed,s+"(");
            }
            paren(n,open,closed+1,s+")");
        }
        
    }
    vector<string> generateParenthesis(int n) {
        paren(n,0,0);
        return ans;
    }
};