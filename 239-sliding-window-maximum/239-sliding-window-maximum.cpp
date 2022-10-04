class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        for(j=0;j<k;j++){
            pq.push({nums[j],j});
        }
        
        res.push_back(pq.top().first);
        
        for(j=k; j<n; j++){
            pq.push({nums[j],j});
            i += 1;
            while(pq.top().second < i){
                pq.pop();
            }
            
            res.push_back(pq.top().first);
        }
        
        return res;
    }
};