class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n-1;
        int top = 0, bottom = m-1;
        
        vector<int> ans;
        
        while(left<=right && top<=bottom){
            
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top += 1;
            if(left>right || top>bottom){
                break;
            }
            
            for(int j=top;j<=bottom;j++){
                ans.push_back(matrix[j][right]);
            }
            right -= 1;
            if(left>right || top>bottom){
                break;
            }
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom -= 1;
            if(left>right || top>bottom){
                break;
            }
            for(int j=bottom;j>=top;j--){
                ans.push_back(matrix[j][left]);
            }
            left += 1;
            
        }
        
        return ans;
    }
};