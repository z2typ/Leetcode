class Solution {
public:
    int util(string s,int n,vector<int>&t){
        if(t[n]!=-1) return t[n];
        if(n==0 || (n==1 && s[0]!='0')) return 1;
        else if(n==1 && s[0]=='0') return 0;
        
        int a=0,b=0;
        
        if(s[n-1]!='0'){
            a = util(s,n-1,t);
        }
        
        if(1<=stoi(s.substr(n-2,2)) && stoi(s.substr(n-2,2))<=26 && s[n-2]!='0'){
            b = util(s,n-2,t);
        }
        
        return t[n] = a+b;
             
    }
    
    int numDecodings(string s) {
        int n = s.length();
        vector<int> t(n+1,-1);
        return util(s,n,t);
    }
};