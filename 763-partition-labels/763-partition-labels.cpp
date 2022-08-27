class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char,int> last_idx;
        
        for(int i=0;i<n;i++){
            last_idx[s[i]] = i;
        }
        int l=0,r=0,k=0;
        vector<int> res;
        while(r<n){
            r = last_idx[s[l]];
            for(k=l;k<r;k++){
                r = max(last_idx[s[k]],r);
            }
            res.push_back(r-l+1);
            r += 1;
            l = r;
        }
        return res;
    }
};