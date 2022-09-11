class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        
        for(int x : nums){
            uset.insert(x);
        }
        
        int count = 0;
        
        for(int x : nums){
            if(!uset.count(x-1)){
                int v = x;
                int ct = 0;
                while(uset.count(v)){
                    v = v+1;
                    ct = ct +1;
                }
                count = max(count , ct);
            }
        }
        
        return count;
        
    }
};