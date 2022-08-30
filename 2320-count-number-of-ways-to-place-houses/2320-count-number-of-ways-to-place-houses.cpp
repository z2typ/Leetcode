#define MOD 1'000'000'007
class Solution {
public:
    int add(long long a, long long b){
        return (a%MOD+b%MOD)%MOD;
    }
    int mul(long long a, long long b){
        return ((a%MOD)*(b%MOD))%MOD;
    }
    vector<int> dp;
    int placeHouse(int n){
        if(n==0){return 1;}
        if(n==1){return 2;}
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = add(placeHouse(n-2),placeHouse(n-1));
        
    }
    int countHousePlacements(int n) {
        dp = vector<int>(n+1,-1);
        int ans = add(placeHouse(n),0);
        return mul(ans,ans);
    }
};