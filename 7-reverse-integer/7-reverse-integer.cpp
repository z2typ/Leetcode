class Solution {
public:
    int reverse(int x) {
        if(x==0) return 0;
        int sign = x/abs(x);
        x = abs(x);
        long long ans = 0;
        
        while(x){
            ans *= 10;
            ans += (x%10);
            x /= 10;
        }
        if(!(ans>=INT_MIN && ans<=INT_MAX)) return 0;
        return sign*ans;
    }
};