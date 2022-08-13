class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum;
        
        prefixSum.push_back(0);
        int sum = 0;
        for(int num : nums){
            sum += num;
            prefixSum.push_back(sum);
        }
        
        unordered_map<int,int> umap;
        int count = 0;
        for(int num : prefixSum){
            if(umap.count(num-k)){
                count += umap[num-k];
            }
            umap[num]++;
        }
        
        return count;
    }
};