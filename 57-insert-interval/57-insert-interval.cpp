class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        
        vector<vector<int>> res;
        
        for(int i=0;i<n;i++){
            if(newInterval[1]<intervals[i][0]){
                res.push_back(newInterval);
                res.insert(res.end(),intervals.begin()+i,intervals.end());
                return res;
            }else if(newInterval[0]>intervals[i][1]){
                res.push_back(intervals[i]);
            }else{
                newInterval = {min(newInterval[0],intervals[i][0]),max(newInterval[1],intervals[i][1])};
            }
            
        }
        res.push_back(newInterval);
        return res;
        
    }
};