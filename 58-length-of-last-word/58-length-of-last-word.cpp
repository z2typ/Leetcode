class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0;
        int j = 0;
        while(s[s.size()-1]==' '){
            s.pop_back();
        }
        for(j=0;j<s.length();j++){
            if(s[j]==' '){
                i = j+1;
            }
        }
        return j-i;
    }
};