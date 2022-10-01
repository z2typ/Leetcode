class Solution {
public:
    int next(int n){
        int digit = 0;
        int next_number = 0;
        while(n){
            digit = n%10;
            n = n/10;
            next_number += digit*digit;
        }
        return next_number;
    }
    
    bool isHappy(int n) {
        if(n==1 || next(n)==1){
            return true;
        }
        int slow = n;
        int fast = next(n);
        while(fast!=1 && next(fast)!=1){
            if(slow==fast){
                return false;
            }
            slow = next(slow);
            fast = next(next(fast));
        }
        return true;
    }
};