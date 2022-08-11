class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        
        set.insert(n);
        while(n!=1){
            
            int n_squared = 0;
            
            while(n!=0){
                n_squared += (n%10)*(n%10);
                n = (n/10);
            }
            
            n = n_squared;
            if(set.count(n)){
                return false;
            }
            set.insert(n);
        }
        return true;
    }
};