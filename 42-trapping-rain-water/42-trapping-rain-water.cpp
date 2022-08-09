class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int maxLeft = height[0], maxRight = height[n-1];
        int waterTrapped = 0;
        while(l < r){
            if(maxLeft < maxRight){
                l += 1;
                maxLeft = max(maxLeft,height[l]);
                waterTrapped += maxLeft - height[l];
            }else{
                r -= 1;
                maxRight = max(maxRight,height[r]);
                waterTrapped += maxRight - height[r];
            }
        }
        return waterTrapped;
    }
};