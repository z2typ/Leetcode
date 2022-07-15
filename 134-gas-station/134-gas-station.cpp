class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int idx = 0;
        int sum_diff = accumulate(gas.begin(),gas.end(),0) - \
            accumulate(cost.begin(),cost.end(),0);
        
        
        if(sum_diff < 0) return -1;
        
        int fuel = 0;
        for(int j=0;j<n;j++){
            fuel += gas[j]-cost[j];
            if(fuel < 0){
                idx = j+1;
                fuel = 0;
            }
            
            
        }
        
        return idx;
    }
};