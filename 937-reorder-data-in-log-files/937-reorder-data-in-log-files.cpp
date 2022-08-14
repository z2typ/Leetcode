class Solution {
public:
    bool isDigit(string s){
        int n = s.size();
        if(0<=s[n-1]-'0' && s[n-1]-'0'<10){
            return true;
        }
        return false;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        int l = n-1;
        int r = n-1;
        for(int r=n-1;r>=0;r--){
            if(isDigit(logs[r])){
                swap(logs[l],logs[r]);
                l -= 1;
            }
        }
        
        sort(logs.begin(),logs.begin()+l+1,[](string a, string b){
            if(a.substr(a.find(' ')) == b.substr(b.find(' '))){
                return a.substr(0,a.find(' ')) < b.substr(0,b.find(' '));
            }
            return a.substr(a.find(' ')) < b.substr(b.find(' '));
        });
        
        return logs;
        
    }
};