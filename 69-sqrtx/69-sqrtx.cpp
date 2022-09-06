class Solution {
public:
    int mySqrt(int x) {
        long int l = 0;
        long int r = x*1ll+1;
        
        while (l<r) {
            long int mid = l + (r-l)/2;
            if (mid*mid > x) {
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l-1;
    }
};