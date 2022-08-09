class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned x = n;
        int count = 0;
        while(x){
            x = x&(x-1);
            count++;
        }
        return count;
    }
};