class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res(n1,-1);
        vector<int> nge(n2,-1);
        stack<int> st;
        
        for(int i=n2-1; i>=0; i--){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }
            if(!st.empty()){
                nge[i] = st.top();
            }
            st.push(nums2[i]);
        }
        
        unordered_map<int,int> umap;
        
        for(int i=0;i<n2;i++){
            umap[nums2[i]] = nge[i];
        }
        
        for(int i=0; i<n1; i++){
            res[i] = umap[nums1[i]];
        }
        
        return res;
        
    }
};