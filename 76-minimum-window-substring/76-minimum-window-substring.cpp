class Solution {
public:
    

    
    string minWindow(string s, string t) {
        int n = s.length();
        
        unordered_map<char, int> freq_t, freq_s;
        int count = t.length();
        for(char ch : t){
            freq_t[ch] += 1;
        }
        int l=0;
        int minWindowLength = INT_MAX;
        int start_idx = n;
        for(int r=0; r<n; r++){
            
            freq_s[s[r]] += 1;
            
            if(freq_t.count(s[r]) && freq_s[s[r]] <= freq_t[s[r]]){
                count -= 1;
            }
            
            while(count==0){ // count == 0 represents a valid window
                if(r-l+1 < minWindowLength){
                    minWindowLength = r-l+1;
                    start_idx = l;
                }
                
                freq_s[s[l]] -= 1;
                if( freq_t.count(s.at(l)) && freq_s.at(s.at(l)) < freq_t.at(s.at(l)) ){
                    count += 1;
                }
                l += 1;
            }
        }
        return s.substr(start_idx,minWindowLength);
    }
};