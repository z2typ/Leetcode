struct mypair{
    int temp;
    int idx;
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<mypair> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans[i] = 0;
                st.push({temperatures[i],i});
            }else{
                while(!st.empty() && st.top().temp <= temperatures[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i] = 0;
                }else{
                    ans[i] = st.top().idx - i;
                }
                
                st.push({temperatures[i],i});
                
            }
        }
        return ans;
        
    }
};