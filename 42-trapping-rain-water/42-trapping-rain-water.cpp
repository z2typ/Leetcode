class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0 , r = n-1;
        
        int leftMax = height[l], rightMax = height[r];
        
        int waterTrapped = 0;
        
        while( l < r ){
            if( leftMax < rightMax){
                l += 1;
                leftMax = max(height[l], leftMax);
                waterTrapped += leftMax - height[l];
            }else{
                r -= 1;
                rightMax = max(height[r], rightMax);
                waterTrapped += rightMax - height[r];
            }
        }
        
        return waterTrapped;
        
    }
};