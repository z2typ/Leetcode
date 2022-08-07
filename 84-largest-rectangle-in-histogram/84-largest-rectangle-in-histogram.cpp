struct validx{
    int value;
    int index;
    validx(int value,int index){
        this->value = value;
        this->index = index;
    }
};
class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        stack<validx> st;
        
        vector<int> right_min(n);
        
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                right_min[i] = n;
                st.push(validx(heights[i],i));
            }else{
                while(!st.empty() && st.top().value >= heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    right_min[i] = n;
                    st.push(validx(heights[i],i));
                }else{
                    right_min[i] = st.top().index;
                    st.push(validx(heights[i],i));
                }
            }
        }
        st = stack<validx>();
        vector<int> left_min(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                left_min[i] = -1;
                st.push(validx(heights[i],i));
            }else{
                while(!st.empty() && st.top().value >= heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    left_min[i] = -1;
                    st.push(validx(heights[i],i));
                }else{
                    left_min[i] = st.top().index;
                    st.push(validx(heights[i],i));
                }
            }
        }
        
        int max_area = INT_MIN;
        
        for(int i=0;i<n;i++){
            max_area = max(heights[i]*(right_min[i]-left_min[i]-1),max_area);
        }
        return max_area;
        
    }
};