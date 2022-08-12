class Solution {
public:
    vector<int> t;
    int numWays(string s,int n){
        
        if(n==0){
            return 1;
        }
        if(t[n]!=-1){
            return t[n];
        }
        
        int a = 0,b = 0;
        
        if(0<=n-1 && s[n-1]!='0'){
            a = numWays(s,n-1);
        }
        
        if(0<=n-2 && s[n-2]!='0' && 1<= stoi(s.substr(n-2,2)) && stoi(s.substr(n-2,2))<=26){
            b = numWays(s,n-2);
        }
        return t[n] = a+b;
        
    }
    
    int numDecodings(string s) {
        int n = s.size();
        t = vector<int>(n+1,-1);
        return numWays(s,n);
    }
};