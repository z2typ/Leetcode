class Solution {
public:
    int util(int n,vector<int>& cost,vector<int>& t){
        if(t[n]!=-1) return t[n];
        if(n==0){
            return t[n] = 0;
        }else if(n==1){
            return t[n] =  0;
        }else{
            return t[n] = min(util(n-1,cost,t)+cost[n-1],util(n-2,cost,t)+cost[n-2]);
        }
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        cost.push_back(0);
        int n = cost.size();
        reverse(cost.begin(),cost.end());
        vector<int> t(n+1,-1);
        
        return util(n,cost,t);
        
    }
};