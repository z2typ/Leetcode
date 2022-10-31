class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        long total_cost = 0;
        long total_gas = 0;
        int n = gas.length;
        
        for(int i=0;i<n;i++){
            total_cost += cost[i];
        }
        for(int i=0;i<n;i++){
            total_gas += gas[i];
        }
        if(total_gas<total_cost)
            return -1;
        long total = 0;
        int ans_index = 0;
        for(int i=0;i<n;i++){
            total += gas[i];
            total -= cost[i];
            if(total<0)
            {
                ans_index = i+1;
                total = 0;
            }
        }
        return ans_index;
    }
}
