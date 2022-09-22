class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int j = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                words.push_back(s.substr(j,i-j));
                j = i+1;
            }
        }
        words.push_back(s.substr(j));
        
        for(string &word : words){
            reverse(word.begin(),word.end());
        }
        string reversed_string = "";
        
        for(string word : words){
            reversed_string += word+" ";
        }
        reversed_string.pop_back();
        return reversed_string;
    }
};