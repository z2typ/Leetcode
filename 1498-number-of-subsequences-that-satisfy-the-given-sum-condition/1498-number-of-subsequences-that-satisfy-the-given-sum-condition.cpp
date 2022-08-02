#define MOD 1'000'000'007
class Solution {
public:
    int add(int a, int b){
        return ((a%MOD)+(b%MOD))%MOD;
    }
    int mul(long long a,long long b){
        return ((a%MOD)*(b%MOD))%MOD;
    }
    
    int power(int x,int y){
        x = (x%MOD);
        if(y==0){
            return 1;
        }
        if(y%2==0){
            int p = power(x,y/2);
            return mul(p,p);
        }else{
            int p = power(x,y/2);
            return mul(mul(p,p),x);
        }
    }
    
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans  = 0;
        
        int i = 0;
        int j = n-1;
        
        while(i<=j){
            if(nums[i]+nums[j] > target){
                j--;
            }else{
                int a = power(2,(j-i));
                ans = add(ans,a);
                i++;
            }
        }
        
        return ans;
    }
};