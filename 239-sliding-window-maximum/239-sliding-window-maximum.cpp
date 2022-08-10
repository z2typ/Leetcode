class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> q;
        
        for(int i=0;i<k;i++){
            q.push({nums[i],i});
        }
        
        vector<int> res;
        res.push_back(q.top().first);
        
        int i = 0;
        int j = k-1;
        
        while(j<n-1){
            
            q.push({nums[j+1],j+1});
            i++;
            j++;
            while(q.top().second<i){
                q.pop();
            }
            
            res.push_back(q.top().first);   
        }
        return res;
        
    }
};