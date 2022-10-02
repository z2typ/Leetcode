class Solution {
public:
    int highestFreq(unordered_map<char, int> &freq){
        int highestFreq = 0;
        for(auto it : freq){
            highestFreq = max(highestFreq, it.second);
        }
        return highestFreq;
    }
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l=0;
        int maxLength = 0;
        unordered_map<char, int> freq;
        for(int r=0; r<n; r++){
            freq[s[r]] += 1;
            
            while(r-l+1-highestFreq(freq) > k){
                freq[s[l]] -= 1;
                l++;
            }
            
            maxLength = max(r-l+1,maxLength);
        }
        return maxLength;
    }
};