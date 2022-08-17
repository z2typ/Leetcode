class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseCode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> uset;
        
        for(string s : words){
            string ans = "";
            for(char c : s){
                ans += morseCode[c-'a'];
            }
            uset.insert(ans);
        }
        
        return uset.size();
    }
};