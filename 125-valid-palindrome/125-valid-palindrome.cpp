class Solution {
public:
    bool isPalindrome(string s) {
        string converted_s = "";
        
        for(char ch : s){
            if('a'<=ch && ch<='z' || 'A'<=ch && ch<='Z' || '0'<=ch && ch<='9'){
                if('A'<=ch && ch<='Z'){
                    converted_s.push_back(ch - ('A'-'a'));
                }else{
                    converted_s.push_back(ch);
                }
            }
        }
        
        int i = 0, j = converted_s.length() - 1;
        
        while(i <= j){
            if(converted_s[i] != converted_s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
        
    }
};