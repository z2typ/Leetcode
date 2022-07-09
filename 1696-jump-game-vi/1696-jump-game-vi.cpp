class Solution {
public:
    

    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        int max_val = nums[0];
        pq.push({nums[0],0});
        // int max_idx = 0;
        for(int i=1;i<=min(k,n-1);i++){
            nums[i] += max_val;
             pq.push({nums[i],i});
            max_val = pq.top().first;
        }

        if(k+1>n-1){
            return nums[n-1];
        }

        for(int i =k+1; i<n ;i++){
            while(!(i-k<=pq.top().second && pq.top().second < i)) {
                pq.pop();
            }
            max_val = pq.top().first;
                
            nums[i] += max_val;

            pq.push({nums[i],i});
        }

        
        return nums[n-1];

    }
};