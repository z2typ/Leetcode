class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> ghtl(n);
        vector<int> ghtr(n);
        int max_left = 0;
        for(int i=0;i<n;i++){
            max_left = max(height[i],max_left);
            ghtl[i] = max_left;
        }
        int max_right = 0;
        for(int i=n-1;i>=0;i--){
            max_right = max(height[i],max_right);
            ghtr[i] = max_right;
        }
        int water_quantity = 0;
        for(int i=0;i<n;i++){
            water_quantity += min(ghtl[i],ghtr[i]) - height[i];
        }
        
        return water_quantity;
    }
};