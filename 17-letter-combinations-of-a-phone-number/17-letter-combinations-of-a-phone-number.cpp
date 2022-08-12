class Solution {
public:
    vector<string> combinations;
    
    void util(string digits,int i,vector<string> &letters,string s=""){
        
        if(i==digits.size()){
            if(i==0)return;
            combinations.push_back(s);
            return;
        }
        
        for(char ch : letters[digits[i]-'0']){
            util(digits,i+1,letters,s+ch);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> letters = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        util(digits,0,letters);
        return combinations;
    }
};