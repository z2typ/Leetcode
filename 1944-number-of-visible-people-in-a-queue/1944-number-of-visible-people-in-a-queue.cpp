class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        
        stack<pair<int,int>> st;
        
        vector<int> res(n); 
        
        for(int i=n-1; i>=0; i--){
            int count = 0;
            while(!st.empty() && st.top().first < heights[i]){
                count++;
                st.pop();
            }
            
            if(st.empty()){
                res[i] = count;
            }else{
                res[i] = count+1;
            }
            
            st.push({heights[i],i});
        }
        
        return res;
    }
};