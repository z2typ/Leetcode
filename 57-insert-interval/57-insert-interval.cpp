class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        vector<vector<int>> ans;
        int idx = -1;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>newInterval[0]){
                idx = i;
                break;
            }
        }
        
        if(idx!=-1){
            intervals.insert(intervals.begin()+idx,newInterval);
        }else{
            intervals.push_back(newInterval);
        }
        
        n = intervals.size();
        vector<int> merged_interval = intervals[0];
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