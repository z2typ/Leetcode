class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_size = s1.size();
        
        if(s2.size()<s1_size){
            return false;
        }
        
        int l = 0, r = s1_size - 1;
        
        unordered_map<char,int> s1_map, s2_map;
        
        for(char ch : s1){
            s1_map[ch]++;
        }
        
        for(int i=0; i<s1_size; i++){
            s2_map[s2[i]]++;
        }
        
        while(true){
            if(s1_map==s2_map){
                return true;
            }

            if(s2_map[s2[l]]==1){
                s2_map.erase(s2[l]);
            }else{
                s2_map[s2[l]]--;
            }
            l++;
            r++;
            if(r>=s2.size()) break;
            s2_map[s2[r]]++;
            
        }
        return false;
        
    }
};