class Solution {
public:
    int mySqrt(int x) {
        long int l = 0;
        long int r = x*1ll;
        if(r==0 || r==1){
            return r;
        }
        while(l<r){
            long int mid = ceil(l + 1.0*(r-l)/2);
            if (mid*mid > x) {
                r = mid - 1;
            }else{
                l = mid;
            }
        }
        return l;
    }
};