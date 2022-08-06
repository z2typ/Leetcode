class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> merged_interval = intervals[0];
        vector<vector<int>> ans;
        for(int i=1;i<n;i++){
            if(merged_interval[1]>=intervals[i][0]){
                merged_interval[1] = max(merged_interval[1],intervals[i][1]);
            }else{
                ans.push_back(merged_interval);
                merged_interval = intervals[i];
            }
        }
        ans.push_back(merged_interval);
        return ans;
    }
};