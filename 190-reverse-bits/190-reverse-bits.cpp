class Solution {
public:
    void set_bit(uint32_t &n,int idx,int value){
        if(value==1){
            n = (n&(~(1<<idx)))|(1<<idx);
        }else{
            n = n&(~(1<<(idx)));
        }
    }
    uint32_t reverseBits(uint32_t n) {
        for(int i=0;i<=15;i++){
            bool right_bit = (n&(1<<i))!=0;
            bool left_bit = (n&(1<<(31-i)))!=0;
            
            set_bit(n,i,left_bit);
            set_bit(n,31-i,right_bit);
        }
        return n;
    }
};