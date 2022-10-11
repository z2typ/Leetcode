class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> text_freq;
        
        for(char ch : text){
            text_freq[ch] += 1;
        }
        
        unordered_map<char,int> balloon_freq;
        string ball = "balloon";
        for(char ch : ball){
            balloon_freq[ch] += 1;
        }
        
        int ans = INT_MAX;
        
        for(auto it : balloon_freq){

            ans = min(ans,text_freq[it.first]/it.second);
        }
        return ans;
    }
};