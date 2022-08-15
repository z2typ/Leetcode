class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start;
        vector<int> end;
        for(vector<int> intvl : intervals){
            start.push_back(intvl[0]);
            end.push_back(intvl[1]);
        }
        
        int count = 0;
        
        int i = 0, j = 0;
        
        int flag = 0;
        vector<vector<int>> ans;
        vector<int> invl = {0,0};
        
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        while(i<n){
            if(start[i]<=end[j]){
                i++;
                count += 1;
            }else{
                count -= 1;
                j++;
            }
            
            if(flag==0 && count!=0){
                invl[0] = start[i-1];
                flag = 1;
            }else if(flag==1 && count==0){
                invl[1] = end[j-1];
                flag = 0;
                ans.push_back(invl);
            }
            
        }
        
        if(flag==1 && count!=0){
            invl[1] = end[n-1];
            ans.push_back(invl);
        }
        return ans;
    }
};