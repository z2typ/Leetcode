class Solution {
public:
    int comp(int a,int b){
        if(a==b){
            return 0;
        }else if(a > b){
            return -1;
        }
        return 1;
    }
    
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int max_len = 1;
        for(int r = 1; r < n; r++){
            if(comp(arr[r-1],arr[r])==0){
                max_len = max(max_len,(r-l));
                l = r;
            }else if( r == n-1 || comp(arr[r-1],arr[r])*comp(arr[r],arr[r+1]) == 1 ){
                // cout<<r<<"Hello!"<<endl;
                max_len = max(max_len,r-l+1);
                l = r;
            }
        }
        return max_len;
    }
};