class Solution {
public:
    int mySqrt(int x) {
        long int l = 0, r = x*1ll;
        while(l<r){
            long int mid = ceil(l + 1.0*(r-l)/2);
            if (mid*mid <= x) {
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return r;
    }
};