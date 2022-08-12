class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& times) {
        
        unordered_map<int,int> umap;
        int count = 0;
        for(int time : times){
            if(umap.count(60-time%60)){
                count += umap[60-time%60];
            }else if(time%60==0){
                count += umap[0];
            }
            umap[time%60]++;
        }
        
        return count;
        
    }
};