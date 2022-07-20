class Solution {
public:
    int numSplits(string s) {
        
        int n = s.length();
        
        vector<int> left_dist_char(n);
        vector<int> right_dist_char(n);
        
        unordered_set<int> uset;
        int dist_char = 0;
        for(int i=0;i<n;i++){
            if(uset.count(s[i])==0){
                dist_char++;
                left_dist_char[i] = dist_char;
                uset.insert(s[i]);
            }else{
                left_dist_char[i] = dist_char;
            }
        }
        
        uset.clear();
        dist_char=0;
        
        for(int i=n-1;i>=0;i--){
            if(uset.count(s[i])==0){
                dist_char++;
                right_dist_char[i] = dist_char;
                uset.insert(s[i]);
            }else{
                right_dist_char[i] = dist_char;
            }
        }
        
        int good_splits = 0;
        
        for(int i=1;i<n;i++){
            if(left_dist_char[i-1]==right_dist_char[i]){
                good_splits++;
            }
        }
        
        return good_splits;
        
    }
};