class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i += 1;
            j -= 1;
        }
        return true;
    }
    
    vector<vector<string>> ans;
    vector<string> res;
    void pp(string &s,int l,int n){
        if(l==n){
            ans.push_back(res);
            return;
        }
        for(int r=l;r<n;r++){
            if(isPalindrome(s,l,r)){
                res.push_back(s.substr(l,r-l+1));
                pp(s,r+1,n);
                res.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        pp(s,0,s.length());
        return ans;
    }
};