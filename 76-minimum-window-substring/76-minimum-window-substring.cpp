class Solution {
public:
    
    bool isValidWindow(unordered_map<char, int> &freq_t, unordered_map<char, int> &freq_s){
        bool isValid = true;
        for(auto it : freq_t){
            if(freq_s[it.first] < it.second){
                isValid = false;
            }
        }
        return isValid;
    }
    
    string minWindow(string s, string t) {
        int n = s.length();
        
        unordered_map<char, int> freq_t, freq_s;
        for(char ch : t){
            freq_t[ch] += 1;
        }
        int l=0;
        int minWindowLength = INT_MAX;
        int start_idx = n;
        for(int r=0; r<n; r++){
            
            freq_s[s[r]] += 1;
            
            while(isValidWindow(freq_t, freq_s)){
                if(r-l+1 < minWindowLength){
                    minWindowLength = r-l+1;
                    start_idx = l;
                }
                freq_s[s[l]] -= 1;
                l += 1;
            }
        }
        return s.substr(start_idx,minWindowLength);
    }
};