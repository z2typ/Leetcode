class Solution {
public:
    string reverseWords(string s) {
        int j = 0;
        string reversed_string = "";
        string word;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                word = s.substr(j,i-j);
                reverse(word.begin(),word.end());
                reversed_string += word+" ";
                j = i+1;
            }
        }   
        word = s.substr(j);
        reverse(word.begin(),word.end());
        reversed_string += word;
        return reversed_string;
    }
};