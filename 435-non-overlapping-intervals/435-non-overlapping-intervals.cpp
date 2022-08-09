class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int l = 0;
        int r = 1;
        
        int count = 0;
        for(int i=1;i<n;i++){
            if(intervals[r][0] < intervals[l][1]){
                if(intervals[l][1] > intervals[r][1]){
                    l = r;
                }
                r++;
                count++;
            }else{
                l = r;
                r++;
            }
        }
        return count;
    }
};